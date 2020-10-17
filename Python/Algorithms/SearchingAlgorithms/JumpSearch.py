"""
jump search algorithm - Implementation

This algorithm iterates through a sorted collection of elements by jumping ahead by fixed 
number of steps [n^(1/2)] until the element compared is greater than the one searched.
Then it will perform a linear search until it found the required number.
"""
 
import math 
  
def jumpSearch( lst , x , n ): 
      
    # Finding the block size to be jumped 
    step = math.sqrt(n) 
      
    # Finding the block where element is 
    # present (if it is present) 
    prev = 0
    while lst[int(min(step, n)-1)] < x: 
        prev = step 
        step += math.sqrt(n) 
        if prev >= n: 
            return -1
      
    # Perform a linear search for x in  
    # block beginning with prev. 
    while lst[int(prev)] < x: 
        prev += 1
          
        # If we reached next block or end  
        # of array, element is not present. 
        if prev == min(step, n): 
            return -1
      
    # If element is found 
    if lst[int(prev)] == x: 
        return prev 
    # If element is not found  
    return -1
  
# Driver code to test function 
lst = [0,1,2,3,4,5,6,7,8,9] 
x = 5
n = len(lst) 
  
# Find the index of 'x' using Jump Search 
index = jumpSearch(lst, x, n) 
  
# Print the index where 'x' is located 
print("Number" , x, "is at index" ,"%.0f"%index) 
    
