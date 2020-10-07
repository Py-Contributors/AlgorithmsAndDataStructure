"""
Title - Strand Sort Algorithm
Purpose - Sorts a given array in non-descending order.
Time Complexity - O(n^2) ~ O(n) best case
"""
import random


class StrandSort:
    """ StrandSort Algorithm Implementation

        arr: an unordered list
        output: return list in non-descending order

        Example:
        >>> sort = StrandSort()
        Strand Sort Algorithm is Initialized.
        >>> sort([2, 6, 3, 1, 9, 4])
        [1, 2, 3, 4, 6, 9]
    """

    def __init__(self):
        print("Strand Sort Algorithm is Initialized.")

    def strandSortIterative(self, arr, output_arr):
        if not arr:  # Nothing to sort if arr is empty
            return

        sublist = []
        sublist.append(arr.pop(0))  # Move first item of arr into sublist

        i = 0
        while i < len(arr):
            if (arr[i] >= sublist[len(sublist) - 1]):
                sublist.append(arr.pop(i))
            i += 1

        if not output_arr:  # First recursive call, move all items into output
            while sublist:
                output_arr.append(sublist.pop(0))
        else:
            # Merge sublist into output
            j = 0
            while sublist:
                if j >= len(output_arr):
                    output_arr.append(sublist.pop())
                    j = 0
                elif (sublist[len(sublist) - 1] > output_arr[j]):
                    j += 1
                else:
                    output_arr.insert(j, sublist.pop())
                    j = 0
        self.strandSortIterative(arr, output_arr)

    def __call__(self, arr):
        output_arr = []
        self.strandSortIterative(arr, output_arr)
        return output_arr


if __name__ == "__main__":
    sort = StrandSort()
    print(sort([5, 2, 1, 6, 10]))  # beginning example

    # more populated examples
    print(sort(random.sample(range(1, 101), 50)))
    print(sort(random.sample(range(1, 201), 100)))
