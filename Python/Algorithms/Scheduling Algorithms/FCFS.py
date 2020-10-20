# -*- coding: utf-8 -*-
"""
Created on Thu Oct 15 17:02:44 2020

@author: KAMESH
"""


import numpy as np


def fcfs(inputdata):
    n = len(inputdata)
    t = 0
    process_queue = []
    for i in range(n):
        process_queue.append([])  # append a list object to the list
        process_queue[i].append(inputdata[i][0])  # added name
        to = int(inputdata[i][1])  # arrival time
        process_queue[i].append(t + to)
        t += to
        process_queue[i].append(int(inputdata[i][2]))  # burst time

    process_queue.sort(key=lambda process_queue: process_queue[1])

# for Finish time
    process_queue[0].append((process_queue[0][1]+process_queue[0][2]))
    for i in range(1, n):
        if process_queue[i][1] < process_queue[i-1][3]:
            process_queue[i].append((process_queue[i-1][3]
                                     + process_queue[i][2]))
        else:
            process_queue[i].append((process_queue[i][1]+process_queue[i][2]))

# for Waiting time
    process_queue[0].append(0)
    for i in range(1, n):
        if process_queue[i-1][3] > process_queue[i][1]:
            process_queue[i].append((process_queue[i-1][3]
                                     - process_queue[i][1]))
        else:
            process_queue[i].append(0)


    for i in range(n):
        process_queue[i].append(process_queue[i][3] - process_queue[i][1])

    pt = []
    tat = []
    wt = []

    for i in process_queue:
        pt.append(i[3])
        tat.append(i[5])
        wt.append(i[4])

    print('ProcessName\tArrivalTime\tBurstTime\tFinishTime\t'
          + 'WaitingTime\tTurnAroundTime')
    for i in range(n):
        print('{:6}'.format(process_queue[i][0]), '\t\t',
              '{:4d}'.format(process_queue[i][1]),
              '\t\t', '{:4d}'.format(process_queue[i][2]),
              '\t\t', '{:4d}'.format(process_queue[i][3]),
              '\t\t', '{:4d}'.format(process_queue[i][4]),
              '\t\t', '{:4d}'.format(process_queue[i][5]), sep=" ")
    print()
    print('Total waiting time: ', sum(wt))
    print('Average process time: ', (sum(pt) / len(pt)))
    print('Average Turn Around Time: ', (sum(tat) / len(tat)))
    print('Standard Deviation of Turnaround Time: ', np.std(tat))


def main():
    inputdata = [[]]
    # filename = 'inp.txt'
    filename = input('Enter input file name: ')
    '''
    name
    arrival time
    burst time
    '''
    with open(filename, 'r') as input_file:
        inputdata = [line[:-1].split(' ') for line in input_file]

    print("Do you want to consider time taken in interrupts?")
    print("1. Yes\n2. No")
    choice = input()
    # choice = 1
    if choice == '1':
        for i in range(0, len(inputdata)):
            inputdata[i][2] = float(inputdata[i][2])
            inputdata[i][2] += float(inputdata[i][3])
        fcfs(inputdata)
    else:
        fcfs(inputdata)


if __name__ == '__main__':
    main()
