"""
Returns the index of a key in a sorted array
or returns -1 if it is not contained
Time complexity - O(log n)
"""


def binarySearch(array, key, left, right):
    """
    Inputs -
    array - A sorted array in which we're going to search for the key
    key - The number to be searched for
    left - The leftmost index at which we need to look
    right - The rightmost index at which we need to look

    =======================================================================
    Output -
    Single integer

    The index of the key if it exists in the array.
    else -1
    """

    mid = left + (right - left) // 2
    if left > right:
        return -1

    if array[mid] == key:
        return mid
    elif array[mid] > key:
        return binarySearch(array, key, left, mid - 1)
    else:
        return binarySearch(array, key, mid + 1, right)


# Driver Code
array = [2, 3, 4, 10, 40]
x = 10
result = binarySearch(array, x, 0, len(array) - 1)
if(result == -1):
    print("Element is not present in array")
else:
    print("Element is present at index", result)

# output: Element is present at index 3

# Driver Code
array = [2, 3, 4, 10, 40]
x = 1
result = binarySearch(array, x, 0, len(array) - 1)
if(result == -1):
    print("Element is not present in array")
else:
    print("Element is present at index", result)

# output: Element is not present in array
