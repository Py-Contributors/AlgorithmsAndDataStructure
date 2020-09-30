# Python program for implementation of Quicksort Sort

def partition(arr, low, high):
	i = (low-1)		 # index of smaller element
	pivot = arr[high]	 # pivot

	for j in range(low, high):
		if arr[j] <= pivot:
			i = i+1
			arr[i], arr[j] = arr[j], arr[i]
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return (i+1)

def quickSort(arr, low, high):		# arr[] is the Array to be sorted
	if len(arr) == 1:
		return arr
	if low < high:
		pi = partition(arr, low, high)
		quickSort(arr, low, pi-1)
		quickSort(arr, pi+1, high)


# Driver code

arr=[1,6,2,78,43,32,167,12,21,13,42]
n = len(arr)
quickSort(arr, 0, n-1)
print("Array after sorting:")
print(arr)
