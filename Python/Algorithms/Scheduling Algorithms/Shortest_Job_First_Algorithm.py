from heapq import heapify, heappop, heappush

"""
Shortest Job First (SJF) is a scheduling algorithm that selects the waiting process with the smallest execution time to execute next. 
This algorithm can minimize the average waiting time of processes in the queue and is often used in batch processing systems. 
The implementation of SJF involves sorting the processes by their execution time and selecting the process with the shortest execution time first. 
This is known as the non-preemptive SJF algorithm. 
In preemptive SJF, the algorithm can interrupt an executing process and switch to a shorter job, if one becomes available. 
Here is an example implementation of the non-preemptive SJF algorithm in Python.
"""


def main():

    # Tasks given with their arrival time and their processing time
    tasks = [[1, 2], [2, 4], [3, 2], [4, 1]]
    # an array to hold tasks while the CPU is executing
    currTasks = []
    # an array to hold the order of tasks
    orderedTasks = []

    # an a rray to hold the index of each task
    for index, task in enumerate(tasks):
        task.append(index)

    # make heap of the tasks in order to find the shortest task in the first index
    heapify(tasks)

    # start from the first task and add it to the currTasks array
    task = heappop(tasks)
    time = task[0]
    currTime = time + task[1]
    orderedTasks.append(task[2])

    while tasks:
        # when the CPU is currently busy and tasks are incoming hold them in currTasks
        while tasks and tasks[0][0] <= currTime:
            start, duration, index = heappop(tasks)
            heappush(currTasks, [duration, index, start])

        # if the CPU is idle and tasks are incoming add them to currTasks
        if not currTasks:
            start, duration, index = heappop(tasks)
            currTime = currTime + duration + start
            orderedTasks.append(index)
        # if there are tasks in queue to be preocessed in currTasks, pop the shortest procssing time and add them to the orderedTasks because they are being excuted by the CPU
        else:
            duration, index, start = heappop(currTasks)
            currTime += duration
            orderedTasks.append(index)

    # if there are tasks left in the queue execute them accordingly
    while currTasks:
        duration, index, start = heappop(currTasks)
        orderedTasks.append(index)

    return orderedTasks


if __name__ == "__main__":
    print("Order of Tasks: ", main())
