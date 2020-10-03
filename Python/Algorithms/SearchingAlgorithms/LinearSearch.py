# Implementation of LinearSearch in python

# Python3 code to linearly search x in arr[].
# If x is present then return its location,
# otherwise return -1


def search(array, key):
    n = len(array)
    for i in range(0, n):
        if array[i] == key:
            return i
    return -1


# Driver Code
array = [2, 3, 4, 10, 40]
x = 10
result = search(array, x)
if result == -1:
    print("Element is not present in array")
else:
    print("Element is present at index", result)

# output: Element is present at index 3
