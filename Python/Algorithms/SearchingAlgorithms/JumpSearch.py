import math
list1= list(map(int ,input().split()))
val=int(input())
gap = math.sqrt(len(list1))
left = 0
while(list1[int(min(gap, len(list1))-1)]<val):
    left = gap
    gap = gap + math.sqrt(len(list1))
    if(left>=len(list1)):
        break
while(list1[int(left)]<val):
    left =left + 1
    if(left== min(gap, len(list1))):
        break
if(list1[int(left)]==val):
        print(int(left))
