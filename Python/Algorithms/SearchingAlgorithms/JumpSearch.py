"""
jump search algorithm - Implementation

This algorithm iterates through a sorted collection of elements by jumping ahead by fixed 
number of steps [n^(1/2)] until the element compared is greater than the one searched.
Then it will perform a linear search until it found the required number.
"""

import math
lst= list(map(int ,input("Enter numbers separated by spaces: ").split()))
num=int(input("Enter the number to be searched: "))
# Finding block size to be jumped
step = math.sqrt(len(lst))

# Finding the block where element is 
# present (if it is present)
prev = 0
while(lst[int(min(step, len(lst))-1)]<num):
    prev = step
    step = step + math.sqrt(len(lst))
    if(prev>=len(lst)):
        print("Not Found")
        exit()

# Doing a linear search for x in  
# block beginning with prev.        
while(lst[int(prev)]<num):
    prev =prev + 1
    # If we reached next block or end  
    # of array, element is not present.
    if(prev== min(step, len(lst))):
        print("Not Found")
        exit()
if(lst[int(prev)]==num):
    # If element is found 
    print(int(prev))
else:
    # If element is not found 
    print("Not Found")
