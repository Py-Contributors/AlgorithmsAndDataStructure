"""
Title - Cocktail Shaker Sort Algorithm
Pupose - Sorts a given array in ascending order.
Time Complexity - O(n^2)
"""
import random


class CocktailSort:
    """ CocktailSort Algorithm Implementation

        arr: an unordered list
        output: return list in ascending order

        Example:
        >>> sort = CocktailSort()
        Cocktail Sort Algorithm is Initialized.
        >>> sort([4, 2, 4, 6, 1, 5])
        [1, 2, 4, 4, 5, 6]

    """

    def __init__(self):
        print("Cocktail Sort Algorithm is Initialized.")

    def __call__(self, arr):
        left_bound = 0
        right_bound = len(arr) - 1
        did_swap = True
        while did_swap:
            did_swap = False

            for i in range(left_bound, right_bound):
                if arr[i + 1] < arr[i]:
                    arr[i + 1], arr[i] = arr[i], arr[i + 1]
                    did_swap = True

            if not did_swap:
                break

            right_bound -= 1

            for i in range(right_bound - 1, left_bound - 1, -1):
                if arr[i + 1] < arr[i]:
                    arr[i + 1], arr[i] = arr[i], arr[i + 1]

            left_bound += 1

        return arr


sort = CocktailSort()
print(sort([5, 2, 1, 6, 10]))  # beginning example

# more populated examples
print(sort(random.sample(range(1, 101), 50)))
print(sort(random.sample(range(1, 201), 100)))
