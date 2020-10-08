"""
Returns the index of a key in a sorted array
or returns -1 if it is not contained
Time complexity - O(log n)
"""
# Python3 implementation of Fibonacci search.


def FibonacciSearch(arr, x, n):
    """
    Inputs =>
    arr - A sorted array in which we're going to search for the key
    x - The number to be searched for
    n - Size of the array
    =======================================================================
    Output =>
    Single integer
    The index of the key if it exists in the array.
    else -1
    """
    # Initialize fibonacci numbers
    fibMMm2 = 0   # (m-2)'th Fibonacci No.
    fibMMm1 = 1  # (m-1)'th Fibonacci No.
    fibM = fibMMm2 + fibMMm1  # m'th Fibonacci

    # fibM is going to store the smallest
    # Fibonacci Number greater than or equal to n
    while (fibM < n):
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1

    # Marks the eliminated range from front
    offset = -1

    # while there are elements to be inspected.
    # Note that we compare arr[fibMm2] with x.
    # When fibM becomes 1, fibMm2 becomes 0
    while (fibM > 1):

        # Check if fibMm2 is a valid location
        i = min(offset + fibMMm2, n - 1)

        # If x is greater than the value at
        # index fibMm2, cut the subarray array
        # from offset to i
        if (arr[i] < x):
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i

        # If x is less than the value at
        # index fibMm2, cut the subarray
        # after i+1
        elif (arr[i] > x):
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1

        # element found. return index
        else:
            return i

    # comparing the last element with x
    if(fibMMm1 and arr[offset + 1] == x):
        return offset + 1

    # element not found. return -1
    return -1


# Driver Code
arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
n = len(arr)
x = 85
print("Found at index:", FibonacciSearch(arr, x, n))

# output: Found at index: 8
