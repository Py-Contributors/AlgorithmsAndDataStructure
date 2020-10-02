"""
Binary search program
It will search the specified number using binary search
Max no of operation taken by the algorithm will be log(sizeof(array))
"""

import math
def binary_search(num_list,find_num):
    si = 0                          #startIndex
    li = len(num_list) - 1          #lastIndex
                   
    No_of_op = 0
    
    # max operation in binary search will be log(size of array)
    # number will be found in operation less than the log(size of array)
    
    while(No_of_op <= math.log(len(num_list))):      
        mid = (si+li) // 2
        No_of_op += 1
        if find_num == num_list[mid] :
            print("found at index", mid+1)
            print("NO of operation happend to find the value:", No_of_op)
            break
        else:
            # if search number is less than the mid then update the last index 
            if find_num < num_list[mid]:
                li = mid-1
            # if search number is greater than the mid then update the first index     
            else:
                si = mid+1
    if No_of_op > math.log(len(num_list)):           
        print("number not found")    
                
#main
numbers=[1,2,3,4,5,6,7,8,9,10] 

binary_search(numbers,10)    # function call
