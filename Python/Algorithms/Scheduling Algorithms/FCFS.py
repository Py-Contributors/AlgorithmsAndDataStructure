import traci
import subprocess
import sys
import numpy as np
from Controller.dynamicController import speedUp, slowDown, slow4conflict
from utils.LoadConfig import read_config
from collections import defaultdict
from utils.visualize import travelTimeVis
from Controller.areaController import laneChangeBan, moveToBar
from domain.const import *


class FcfsController:
    '''
    initialize before simulation begin
    '''
    def __init__(self, dist=50.0):
        self.dist = dist
        self.vehsInfo = dict()
        self.in_loop = ['u_1', 'l_1', 'b_1', 'r_1', 'u_2', 'l_2', 'b_2', 'r_2','u_3', 'l_3', 'b_3', 'r_3']
        self.exit_loop = ['uo_1', 'bo_1', 'ro_1', 'lo_1', 'uo_2', 'bo_2', 'ro_2', 'lo_2', 'uo_3', 'bo_3', 'ro_3', 'lo_3']
        self.entryTime = dict()  # record vehicles' id and corresponding entry time
        self.occupancy = dict()
        self.illegal = dict()
        self.conflictDict = read_config()
        # for calculating travel time
        self.travelDict = defaultdict(list)

    def __str__(self):
        return "fcfs"

    def getVehsInfo(self):
        # Before every simulation step, first clear the dict to delete previous information
        self.vehsInfo.clear()
        vids = traci.vehicle.getIDList()
        for vid in vids:
            if traci.vehicle.getLaneID(vid) in LANE_ID:
                if traci.vehicle.getLanePosition(vid) > LANE_LENGTH - self.dist:
                    self.vehsInfo[vid] = [traci.vehicle.getLaneID(vid), traci.vehicle.getLanePosition(vid)]
        self._addEntryTime()
        # sort by entry time
        tmp = sorted(self.vehsInfo.items(), key=lambda x: x[1][2])
        self.vehsInfo.clear()
        for index in range(len(tmp)):
            self.vehsInfo[tmp[index][0]] = tmp[index][1]

    def _addEntryTime(self):
        dataCollector = []
        for eid in self.in_loop:
            # [(veh_id, veh_length, entry_time, exit_time, vType)]
            if traci.inductionloop.getVehicleData(eid) != []:
                dataCollector.append(traci.inductionloop.getVehicleData(eid))
            if np.array(dataCollector).size != 0:
                for vindex in range(len(dataCollector)):
                    vid = dataCollector[vindex][0][0]
                    t = dataCollector[vindex][0][2]
                    self.entryTime[vid] = t
        if self.vehsInfo:
            for vid in list(self.vehsInfo.keys()):
                if len(self.vehsInfo[vid]) < 3:
                    self.vehsInfo[vid].append(self.entryTime[vid])

    def _testLeader(self, vid):
        '''
        test whether the vehicle vid exists a leader in Buffed Area
        :return:boolean  (if exists a leader, return True)
        '''
        vPos = self.vehsInfo[vid][1]    # current vehicle's position on the lane
        leader = traci.vehicle.getLeader(vid)
        flag = False
        if leader is not None:
            interval = leader[1]            # the safe distance between vehicle and its leader
            vbPos = vPos - (LANE_LENGTH - self.dist)
            if vbPos + interval < self.dist:
                flag = True
        return flag

    def desiredArrTime(self, vid):
        '''
        :param vid: vehicle id in sumo
        :return: (the timeStamp when vehicle entry the intersection, the time vehicle spending in crossing the intersection)
        '''
        # dir1 is current direction, dir2 is future's direction
        dir1, dir2 = vid.split('.')[0].split('To')
        # judge if the vehicle needs to turn in the intersection
        straight_dict = {'left': 'Right', 'right':'Left', 'up': 'Below', 'below':'Up'}
        longTurn_dict = {'left': 'Up', 'right':'Below', 'up':'Right', 'below':'Left'}
        if straight_dict[dir1] == dir2:
            # don't need to slow down, just go straight with max allowed speed
            arrTime = speedUp(vid)
            depTime = STRAIGHT / traci.vehicle.getAllowedSpeed(vid)
        else:
            # need to turn, slow down to pass the intersection
            arrTime = slowDown(vid, 4.0)
            if longTurn_dict[dir1] == dir2:
                # long turning
                depTime = LEFTTURN / 4.0
            else:
                depTime = RIGHTTURN / 4.0
        return (arrTime, depTime)

    def _applyReservation(self):
        # obtain the information of vehicles in Buffered Area
        self.getVehsInfo()
        for vid in list(self.vehsInfo.keys()):
            if vid not in list(self.occupancy.keys()):
                if not self._testLeader(vid):
                    # if there isn't a leader, the machine may accept a vehicle's request
                    if not self.occupancy:
                        # if occupancy information is empty, then a car can run in max allowed speed
                        self.occupancy[vid] = self.desiredArrTime(vid)
                        if vid in self.illegal.keys():
                            del self.illegal[vid]
                    else:
                        # the vehicle's route has no conflict with those in occupancy dict, allow its request
                        flag = 0
                        for existsVeh in list(self.occupancy.keys()):
                            if vid.split('.')[0] in self.conflictDict[existsVeh.split('.')[0]]:
                                flag = 1
                        if flag == 0:
                            self.occupancy[vid] = self.desiredArrTime(vid)
                            if vid in self.illegal.keys():
                                del self.illegal[vid]
        # obtain conflict or follower vehicles' information
        for vid in list(self.vehsInfo.keys()):
            if vid not in list(self.occupancy.keys()):
                # in every simulation step, if a vehicle have no permission to entry the intersection,
                # and at the same time, the vehicle is in front of the junction, it will stop and wait
                self.illegal[vid] =slow4conflict(vid)
        return None

    def handleReservation(self):
        self._applyReservation()
        for vid in list(self.occupancy.keys()):
            try:
                if vid not in list(self.vehsInfo.keys()) and traci.vehicle.getLaneID(vid) not in JUNCTION_ID:
                    # neither in the control area nor at the intersection
                    del self.occupancy[vid]
            except Exception as e:
                print(e)

        for vid in list(self.illegal.keys()):
            try:
                if vid not in list(self.vehsInfo.keys()) and traci.vehicle.getLaneID(vid) not in JUNCTION_ID:
                    del self.illegal[vid]
            except Exception as e:
                print(e)
        # print(self.occupancy)
        # print(self.illegal)
        return None

    def _collectTravelTime(self):
        '''
        calculate the travel time between the start of incoming lane's Buffered Area and the exit of the junction
        :return: travel time list for all vehicles
        '''
        for ieid in self.in_loop:
            # [(veh_id, veh_length, entry_time, exit_time, vType), ...]
            for vehData in traci.inductionloop.getVehicleData(ieid):
                veh_id = vehData[0]
                exit_time = vehData[3]
                if exit_time != -1.0:
                    self.travelDict[veh_id].append(exit_time)
        for oeid in self.exit_loop:
            for vehData in traci.inductionloop.getVehicleData(oeid):
                veh_id = vehData[0]
                entry_time = vehData[2]
                if entry_time != -1.0 and veh_id in list(self.travelDict.keys()):
                    if len(self.travelDict[veh_id]) == 1:
                        self.travelDict[veh_id].append(entry_time)

    def simOneStep(self):
        self.handleReservation()
        laneChangeBan()
        self._collectTravelTime()

    def _statistic(self, all_direction = True):
        '''
        Statistics of travel time in simulation
        :param all_direction: determine whether direction division is needed
        :return: if all_direction is True, return a list including all vehicles' travel time; otherwise, return a dict
        with different direction's travel time information
        '''
        straight_dict = {'left': 'Right', 'right':'Left', 'up': 'Below', 'below':'Up'}
        longTurn_dict = {'left': 'Up', 'right':'Below', 'up':'Right', 'below':'Left'}
        dirTravelTime = defaultdict(list)
        for vid in list(self.travelDict.keys()):
            flow_name = vid.split('.')[0]
            dir1, dir2 = flow_name.split('To')
            if len(self.travelDict[vid]) == 2:
                if straight_dict[dir1] == dir2:
                    dirTravelTime[flow_name].append(max(self.travelDict[vid][1] - self.travelDict[vid][0] - 8.0, 0.0001))
                elif longTurn_dict[dir1] == dir2:
                    dirTravelTime[flow_name].append(max(self.travelDict[vid][1] - self.travelDict[vid][0] - 19.1428, 0.0001))
                else:
                    dirTravelTime[flow_name].append(max(self.travelDict[vid][1] - self.travelDict[vid][0] - 12.8928, 0.0001))
        if all_direction:
            return sum([v for k, v in dirTravelTime.items()], [])
        return dirTravelTime

    def travelTimePlot(self, all_direction):
        statistic = self._statistic(all_direction=all_direction)
        travelTimeVis(statistic, "FCFS")

if __name__ == "__main__":
    PORT = 8813
    sumoBinary = "D:\\sumo\\bin\\sumo-gui"      # your sumo binary path
    cfg_filepath = "../sumoFiles\\no_signal\\intersection.sumocfg"
    sumoProcess = subprocess.Popen([sumoBinary, "-c", cfg_filepath, "--remote-port", str(PORT)],
        stdout=sys.stdout, stderr=sys.stderr)
    traci.init(PORT)
    t = FcfsController()
    for sim_step in range(600):
        traci.simulationStep()
        t.simOneStep()
    traci.close()
    t.travelTimePlot(all_direction=True)
