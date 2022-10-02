# Python3 program for the above approach

# Function to sort the array using
# the Slow sort
def slow_sort(A, i, j):
    # Recursion break condition
    if i >= j:
        return

    # Store the middle value
    m = (i + j) // 2

    # Recursively call with the
    # left half
    slow_sort(A, i, m)

    # Recursively call with the
    # right half
    slow_sort(A, m + 1, j)

    # Swap if the first element is
    # lower than second
    if (A[j] < A[m]):
        temp = A[m]
        A[m] = A[j]
        A[j] = temp

    # Recursively call with the
    # array excluding the maximum
    # element
    slow_sort(A, i, j - 1)


# Function to print the array
def printArray(arr, size):
    for i in range(size):
        print(arr[i], end=" ")


# Driver Code
if __name__ == '__main__':
    arr = list(map(int, input().split()))
    n = len(arr)

    # Function Call
    slow_sort(arr, 0, n - 1)

    # Print the sorted array
    printArray(arr, n)

