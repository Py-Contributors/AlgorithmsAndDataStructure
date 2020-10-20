
a = []
burst_time = []
waiting_time = []
turn_around_time = []
total_waiting_time = 0
total_turnaround_time = 0
sum = 0 
n = int(input("Enter the number of processes"))
for i in range (n): 
    a.append(input("Enter process id "))
    burst_time.append(int(input("Enetr corresponding burst time")))

for i in range (n):
    for j in range (i,n):
        if(a[i]>=a[j]):
            temp1 = a[i]
            a[i] = a[j]
            a[j] = temp1
            temp1 = burst_time[i]
            burst_time[i]=burst_time[j]
            burst_time[j] = temp1

print("The turn-around times are ")
for i in range (n):
    sum = sum + burst_time[i]    
    turn_around_time.append(sum)
    total_turnaround_time = total_turnaround_time + sum
    print(str(a[i])+" "+str(sum))
print("The waiting times are ")
for i in range (n):
    temp = turn_around_time[i]-burst_time[i]
    print(str(a[i])+" "+str(temp))
    waiting_time.append(temp)
    total_waiting_time = total_waiting_time + temp
print( "Processes Burst time " + " Waiting time " + " Turn around time")
for i in range (n):
    print(" " + str(a[i]) + "\t\t" + 
                    str(burst_time[i]) + "\t\t" + 
                    str(waiting_time[i]) + "\t\t " + 
                    str(turn_around_time[i])) 
print("The average turnaround time is ")
print(total_turnaround_time/n)
print("The average waiting time is ")
print(total_waiting_time/n)
