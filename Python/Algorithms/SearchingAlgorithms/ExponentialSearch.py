# Implementation of Exponential Search

# Python 3 Code will expand range of searching exponentially
# until required element is included and then
# perform Binary Search within that range

def ExponentialSearch(array, size, x):
    if(array[0]) == x:  # Checking for required element in first position
        return 0
    i = 1
    while (i < size) and (array[i] <= x):  # Expanding range
        i = i * 2
    return BinarySearch(array, i / 2, min(i, size), x)


def BinarySearch(array, left, right, x):  # Basic Binary Search Algorithm
    if (right >= left):
        mid = int(left + (right - left) / 2)
        if (array[mid] == x):
            return mid
        if (array[mid] > x):
            return BinarySearch(array, left, mid - 1, x)
        return BinarySearch(array, mid + 1, right, x)
    return -1  # Returns -1 when element found withing range by Binary Search


# Driver Code
array = [12, 20, 69, 420, 666]
size = len(array)
x = 420
result = ExponentialSearch(array, size, x)
if result == -1:
    print("Element doesn't exist in the array!")
else:
    print("Element exists within array at index position %d!" % result)

# Example Output:
#  Element exists within array at index position 3!
