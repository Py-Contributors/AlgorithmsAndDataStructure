class SelectiontionSort:
    """ insertionSort Algorithm Implementation in Python 3

    arr : Unorded list
    output : Return list in ascending order.
    time complexity : O(n2) as there are two nested loop
    Auxiliary Space: O(1)

    Example :
    >>> sort = SelectionSort
    >>> sort([4,2,6,5,9,8])
    [2, 4, 5, 6, 8, 9]"""

    def __init__(self):
        print("Selection Sort Algorithm is Initialized")

    def __call__(self, arr):
        for i in range(len(arr)):

            # Find the minimum element in remaining
            # unsorted array
            min_idx = i
            for j in range(i + 1, len(arr)):
                if arr[min_idx] > arr[j]:
                    min_idx = j

    # Swap the found minimum element with
    # the first element
            arr[i], arr[min_idx] = arr[min_idx], arr[i]

        return arr
