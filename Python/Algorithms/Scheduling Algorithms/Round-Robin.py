import Queue,csv

MaxTime = 300
ContextSwitch = 0

class Process: # Definining Process
    def __init__(self, pid, arrival, burst):
        self.pid = pid
        self.arrival = arrival
        self.burst = burst
    def __str__(self):
        return '|ID:{:3d}| Arrival Time:{:3d}| Burst Time:{:3d}|'.format(self.pid,self.arrival,self.burst)


class Simulator:
    def __init__(self, tq):
        self.quantum = tq
        self.clock = 0
        self.list = []
        self.ProcessQueue = Queue.Queue()
        self.RunQueue = Queue.Queue()

    def ProcessAdd(self, pid, arrival, burst):
        process = Process(pid, arrival, burst)
        self.list.append(process)

    def Check(self, clock):
        for process in self.list:
                if process.arrival == self.clock:
                    self.ProcessQueue.put(process)
                    break

    def Scheduling(self):
        self.timer = 0
        for process in self.list:
                if process.arrival == self.clock:
                    self.ProcessQueue.put(process)
                    break
        while self.clock < MaxTime:
            self.clock = self.clock + 1
            self.Check(self.clock)
            
            if not self.ProcessQueue.empty():
                process = self.ProcessQueue.get()
                if(process.burst < self.quantum):
                    self.timer = self.timer + process.burst
                    bur = process.burst
                    process.burst = 0
                    print '|ID:{:3d}| Start:{:3d}| End:{:3d}| Time Left:{:3d}'.format(process.pid, self.timer - bur, self.timer, process.burst)
                else:
                    process.burst = process.burst - self.quantum
                    print '|ID:{:3d}| Start:{:3d}| End:{:3d}| Time Left:{:3d}'.format(process.pid, self.timer, self.timer + self.quantum, process.burst)
                    self.timer = self.timer + self.quantum
            self.clock = self.clock + 1
            self.Check(self.clock)

            if not process.burst <= 0:
                self.ProcessQueue.put(process)
