import math

def jumpSearch( arr , x , n ): 
      
    # Finding block size to be jumped 
    step = math.sqrt(n) 
      
    # Finding the block where element is 
    # present (if it is present) 
    prev = 0
    while arr[int(min(step, n)-1)] < x: 
        prev = step 
        step += math.sqrt(n) 
        if prev >= n: 
            return -1
      
    # Doing a linear search for x in  
    # block beginning with prev. 
    while arr[int(prev)] < x: 
        prev += 1
          
        # If we reached next block or end  
        # of array, element is not present. 
        if prev == min(step, n): 
            return -1
      
    # If element is found 
    if arr[int(prev)] == x: 
        return prev 

    # function will return -1 if element is not present  
    return -1
  
# exceution strarts from here

arr = list(map(int,input("Enter the array elements (in space saparated format and array must be sorted) : ").split()))

x = int(input("Enter the no. which is to be searched : "))
n = len(arr) 
flag = 0
# Find the index of 'x' using Jump Search 
b = sorted(arr)
if arr != b :
    print("Array must be sorted!!! Now you will get the index of element in sorted array")
    flag = 1

index = jumpSearch(b, x, n) 
  
# Print the index where 'x' is located 
if index!=-1:
    if flag == 1:
        print("Number" , x, "is at index" ,"%.0f"%index," in sorted form of entered array")
    else:
        print("Number" , x, "is at index" ,"%.0f"%index)
else:
    print("Number" , x, " is not present in the list!") 
  