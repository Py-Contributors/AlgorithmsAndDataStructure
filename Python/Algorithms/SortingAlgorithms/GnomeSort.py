"""
Title - Gnome Sort Algorithm
Pupose - Sorts a given array in ascending order.
Time Complexity - O(n^2)
"""
import random


class GnomeSort:
    """ GnomeSort Algorithm Implementation

        arr: an unordered list
        output: return list in ascending order

        Example:
        >>> sort = GnomeSort()
        Gnome Sort Algorithm is Initialized.
        >>> sort([2, 6, 3, 1, 9, 4])
        [1, 2, 3, 4, 6, 9]

    """

    def __init__(self):
        print("Gnome Sort Algorithm is Initialized.")

    def __call__(self, arr):
        i = 0
        while i < len(arr):
            if i == 0:
                i += 1
            if arr[i - 1] <= arr[i]:
                i += 1
            else:
                arr[i - 1], arr[i] = arr[i], arr[i - 1]
                i -= 1
        return arr


sort = GnomeSort()
print(sort([5, 2, 1, 6, 10]))  # beginning example

# more populated examples
print(sort(random.sample(range(1, 101), 50)))
print(sort(random.sample(range(1, 201), 100)))
