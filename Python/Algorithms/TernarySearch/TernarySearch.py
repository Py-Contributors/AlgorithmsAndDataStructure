# recursive approach to ternary search
# Array A is sorted
def ternarySearch(left, right, key, A):
	if right >= left:

		# devide the array into three parts let the indexes be mid1 mid2
		mid1 = left + int((right - left)/3)
		mid2 = right - int((right - left)/3)

		# if the key is present at the indexes used for division
		if (A[mid1] == key): 
			return mid1
		
		if (A[mid2] == key): 
			return mid2
		### If the key is not present on the above indexes then recur for the parts it can be present in just like binary search
		if (key < A[mid1]): 

			# The key lies in between left and mid1
			return ternarySearch(left, mid1 - 1, key, A)
		
		elif (key > A[mid2]): 

			# The key lies in between mid2 and right
			return ternarySearch(mid2 + 1, right, key, A)
		
		else: 

			# The key lies in between mid1 and mid2
			return ternarySearch(mid1 + 1, mid2 - 1, key, A)
	#if the key is not found in A then
	return "Key not found in the given array"

#Complexity = log n

# if the array is not sorted then Complexity the sorting the array makes Complexity n log n.
