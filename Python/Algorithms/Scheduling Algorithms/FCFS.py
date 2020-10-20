print("Enter number of processes")
n=int(input(""))
print("Enter ids")
a=list(map(int,input().split()))
print("Enter arrival times")
b=list(map(int,input().split()))
print("Enter burst times")
c=list(map(int,input().split()))
e=[]
d=[]
r=[]
sum1=0
for x in range(len(c)):
    sum1+=c[x]
    print (sum1,end=" ")
    d.append(sum1)
x=zip(d,b)
for i,j in x:
    e.append(i-j)
print(e)
t=sum(e)
print("Average turnaround time is",t/n, end=" ")
y=zip(e,c)
for o,p in y:
    r.append(o-p)
z=sum(r)
print("Average waiting time is",z/n,end=" ")
