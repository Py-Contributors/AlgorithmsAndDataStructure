# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 19:54:41 2020

@author: KAMESH
"""


at = []  # Arrival time
ct = []  # Completion time
wt = []  # Waiting time
tat = []  # TurnAround time
pro = []  # Processes
stat = 0
m = 0

n = int(input("Enter Number of processes:"))

for i in range(0, n):
    pro.insert(i, i+1)
# Burst-time-Input
bt = int(input("Enter Burst Time:"))
# Arrival-Time-Input
at = list(map(int, input("Enter Arrival Time:").strip().split()))


# Arrival-Time-Sorted
at.sort()

# Completion-Time
for i in range(0, n):
    stat = stat+bt
    ct.insert(i, stat)

# TurnAround-Time
for i in range(0, n):
    tat.insert(i, ct[i] - at[i])

print("\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\t TurnAround Time  ")
for i in range(n):
    print(str(pro[i]) + "\t\t\t" + str(at[i]) + "\t\t\t\t" + str(bt) + "\t\t\t" + str(ct[i]) + "\t\t\t\t " + str(tat[i]))

    Avgct = + ct[i]
    Avgtat = + tat[i]
    Avgct = float(Avgct/n)
    Avgtat = float(Avgtat/n)

print("Average Completion Time is:", Avgct)
print("Average Trunaround Time is:", Avgtat)
