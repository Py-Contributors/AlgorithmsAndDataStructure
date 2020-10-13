class QuickSort:
    """ Pure implementation of quick sort algorithm in Python

        arr : Unorded list
        output : Return list in ascending order.

        Examples:
        >>> sort = QuickSort()
        >>> sort([0, 5, 3, 2, 2])
        [0, 2, 2, 3, 5]
        """
    def __init__(self):
        print("Quick Sort Algorithm is Initialized")

    def __call__(self, arr):

        length = len(arr)
        if length <= 1:
            return arr
        else:
            pivot = arr.pop()

            greater, lesser = [], []
            for element in arr:
                if element > pivot:
                    greater.append(element)
                else:
                    lesser.append(element)
            return self.__call__(lesser) + [pivot] + self.__call__(greater)


sort = QuickSort()
print(sort([10, 9, 5, 11, 2]))
