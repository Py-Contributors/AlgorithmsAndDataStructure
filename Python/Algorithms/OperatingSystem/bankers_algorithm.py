# Banker's Algorithm
# This algorithm takes maximum number of processes and
# resources available to determine whether the system
# is in a safe state and no deadlock can occur

import sys


def calculateNeed(P, R, need, maxm, alloted):
    """Finds need of each process
       P = Number of processes
       R = Number of resources
       need = array containing need of each processes
       maxm = maximum resource that can be allocated to each process
       alloted = alloted resource to each process"""

    for i in range(P):
        for j in range(R):
            need[i][j] = maxm[i][j] - alloted[i][j]


def isSafe(P, R, processes, available_array, max_R, alloted):
    need = []
    for i in range(P):
        temp = []
        for j in range(R):
            temp.append(0)
        need.append(temp)

    calculateNeed(P, R, need, max_R, alloted)

    # mark all processes as unfinished
    finish = [0] * P

    # safe sequence array
    safeSeq = [0] * P

    # make a copy of available resources
    work = [0] * R
    for i in range(R):
        work[i] = available_array[i]

    # while all processes not finished or system not in safe state
    count = 0
    while(count < P):
        # find an unfinished process whose
        # needs can be satisfied
        found = False
        for p in range(P):

            if(finish[p] == 0):

                for j in range(R):
                    if(need[p][j] > work[j]):
                        break

                if(j == R - 1):

                    for k in range(R):
                        work[k] += alloted[p][k]
                    safeSeq[count] = p
                    count += 1

                    finish[p] = 1
                    found = True
        if found is False:
            print("System not in safe state")
            return False

    print("System is in safe state")
    print("Safe Sequence is: ")
    print(*safeSeq)
    return True


if __name__ == "__main__":
    n = len(sys.argv)

    script_name = sys.argv[0]

    P = int(input("Enter number of processes\n"))
    R = int(input("Enter number of resources\n"))

    process_array = list(map(int, input("Enter process name separated by space\n").split()))

    available_array = list(map(int, input("Enter total resources separated by space\n").split()))

    max_R = [[0] * R] * P
    for i in range(P):
        max_R[i] = list(map(int, input(f"Enter max resources for process {process_array[i]}\n").split()))

    allotted = [[0] * R] * P
    for i in range(P):
        allotted[i] = list(map(int, input(f"Enter alloted resources for process {process_array[i]}\n").split()))

    #  check if system is in safe state
    isSafe(P, R, process_array, available_array, max_R, allotted)
