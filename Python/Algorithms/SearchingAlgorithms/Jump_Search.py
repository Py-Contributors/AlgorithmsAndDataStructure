# Python3 code to implement Jump Search 

# If x is present then return its location, 
# otherwise return -1 
import math 

def jumpSearch( arr , x , n ): 
	
	step = math.sqrt(n) 
	prev = 0
	while arr[int(min(step, n)-1)] < x: 
		prev = step 
		step += math.sqrt(n) 
		if prev >= n: 
			return -1
	
	while arr[int(prev)] < x: 
		prev += 1
		
		if prev == min(step, n): 
			return -1
	
	# If element is found 
	if arr[int(prev)] == x: 
		return prev 
	
	return -1

# Driver code to test function 
arr = [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 
	34, 55, 89, 144, 233, 377, 610 ] 
x = 55
n = len(arr) 

# Find the index of 'x' using Jump Search 
index = jumpSearch(arr, x, n) 

# Print the index where 'x' is located 
print("Number" , x, "is at index" ,"%.0f"%index) 

