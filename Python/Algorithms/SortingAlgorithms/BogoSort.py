"""
Title - Bogo Sort
"""
import random


class BogoSort:
    """ Bogo Sort Algorithm Implementation
        arr: an unordered list
        output: return list in non-descending order
        Example:
        >>> sort = BogoSort()
        Bogo Sort Algorithm is Initialized.
        >>> sort([9, 8, 7, 6, 5, 4, 3, 2, 1])
        [1, 2, 3, 4, 5, 6, 7, 8, 9]
    """

    def __init__(self):
        print("Bogo Sort Algorithm is Initialized.")

    def __call__(self, arr):
        while sorted(arr) != arr:
            random.shuffle(arr)
        return arr


if __name__ == "__main__":
    sort = BogoSort()
    print(sort([9, 8, 7, 6, 5, 4, 3, 2, 1]))
