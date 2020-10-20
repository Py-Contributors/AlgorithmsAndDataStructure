# -*- coding: utf-8 -*-
"""
Created on Thu Oct 15 17:02:44 2020

@author: KAMESH
"""


list1 = []
j=[]
n = int(input("NO of processes : "))
print("Process\tBurst time\tArrival time")
for i in range(n):
    input1 = list(map(int, input().split()))
    list1.append(input1)
    j.append(list1[i][0])
list1.sort(key = lambda x: x[2])
c = 0
for i in range(n):
    if list1[i][2] <= c :
        list1[i].append(c-list1[i][2])
        list1[i].append(c + list1[i][1])
        c = c + list1[i][1]

print("process sequence : ", end='')
for i in range(n):
    print("P", list1[i][0], sep="", end='\t')
print("\nProcess Burst time Arrival time Waiting time Completion time")
for i in range(n) :
    print(list1[i][0],list1[i][1],list1[i][2],list1[i][3],list1[i][4],sep="\t\t\t")
awt = 0
print("\nAverage waiting time : ", end="")
for i in range(n):
    awt += list1[i][3]
print("{:.2f}".format(awt / n))
ct = 0
print("Average Turnaround time : ", end="")
for i in range(n):
    ct += list1[i][4] - list1[i][2]
print("{:.2f}".format(ct / n))
