# Jump Search algorithm
# Jump search is another searching algorithm, which is faster than linear search, but slower than binary search.
# Its complexity is O(squareroot(n)).
# Note : The array must be sorted in order fr it to work

from math import sqrt


def jumpSearch(arr , x , n):

    step = sqrt(n)

    previous = 0

    # While you haven't found a block, keep on stepping
    while arr[int(min(step, n)-1)] < x:
        previous = step
        # Let the previous
        step += sqrt(n)
        if previous >= n:
            return -1

    # Perform linear search on the block to find it
    while arr[int(previous)] < x:
        previous += 1

        if previous == min(step, n):
            return -1

    if arr[int(previous)] == x:
        return previous

    return -1
