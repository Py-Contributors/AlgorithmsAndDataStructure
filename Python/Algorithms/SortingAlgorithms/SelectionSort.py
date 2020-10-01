class SelectionSort:
    """ SelectionSort Algorithm Implementation in Python 3
    arr : Unorded list
    output : Returns list in ascending order.
    time complexity : O(n^2)
    Example :
    >>> sort = SelectionSort()
    Selection Sort Algorithm is Initialized
    >>> sort([19, 11, -5, 0, 5, 7])
    [-5, 0, 5, 7, 11, 19]
    """

    def __init__(self):
        print("Selection Sort Algorithm is Initialized")

    def __call__(self, arr):
        for i in range(len(arr)):
            min_idx = i
            for j in range(i + 1, len(arr)):
                if arr[j] < arr[min_idx]:
                    min_idx = j
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
        return arr
