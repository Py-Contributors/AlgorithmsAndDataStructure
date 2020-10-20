def fcfs():
    #process_number is not needed for this program as the next line is
    #spliting the input string into a list of process
    process_number = int(input())
    #takes the process times as string and split them when get <space>
    #and store them in a list
    list_of_process = [int(x) for x in input().split(" ")]
    #waiting time of first process is always 0
    waiting_time = [0,]
    #turnaround time of first process is always the execution time of that process
    turnaround_time = [list_of_process[0],]
    #response time of first process is always 0
    response_time = [0,]
    #calculate various time
    for i in range(1,process_number):
        #waiting time = previous waiting time + previous process execution time
        waiting_time.append(waiting_time[i-1]+list_of_process[i-1])
        #turnaround time = previous turnaround time + process execution time
        turnaround_time.append(turnaround_time[i-1]+list_of_process[i])
        #response time = previous waiting time + previous process execution time
        response_time.append(waiting_time[i-1]+list_of_process[i-1])

    #calculate average times
    average_waiting_time = sum(waiting_time)/process_number
    average_turnaround_time = sum(turnaround_time)/process_number
    average_response_time = sum(response_time)/process_number
    #print the times of processes
    names = ["Process name","Waiting time","Turnaround time","Response time"]
    print("{:<20} {:<20} {:<20} {:<20}".format(names[0],names[1],names[2],names[3]))
    for i in range(len(list_of_process)):
        print("Process {:<12} {:<20.2f} {:<20.2f} {:<20.2f}".format(i+1,waiting_time[i],turnaround_time[i],response_time[i]))
    #print the average times of processes
    avg_names = ["Average waiting time","Average turnaround time","Average response time"]
    print("{:<30} {:<30} {:<30}".format(avg_names[0],avg_names[1],avg_names[2]))
    print("{:<30.2f} {:<30.2f} {:<30.2f}".format(average_waiting_time,average_turnaround_time,average_response_time))
