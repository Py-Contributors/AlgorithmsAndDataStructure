# Python3 code to implement iterative Binary 
# Search. 
#In binary search we have a sorted array either in ascending or descending order
# It returns location of x in given array arr 
# if present, else returns -1 
def binarySearch(arr, lower, upper, x): 
	while lower <= upper: 
		mid = lower + (upper - lower) // 2; 
		# Check if x is present at mid 
		if arr[mid] == x: 
			return mid 
		# If x is greater, ignore left half 
		elif arr[mid] < x: 
			lower = mid + 1
		# If x is smaller, ignore right half 
		else: 
			upper = mid - 1
	# If we reach here, then the element 
	# was not present 
	return -1
# Driver Code 
arr = [int(i) for i in (input('Enter element with space in between').split())]#inputting list of numbers from users
x = int(input('Enter element to be searched'))#element to be searched
# Function call 
result = binarySearch(arr, 0, len(arr)-1, x) 
if result != -1: 
	print ("Element is present at index % d" % result) 
else: 
	print ("Element is not present in array") 
