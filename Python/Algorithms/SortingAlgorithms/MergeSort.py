def merge(self, left, right):
    if len(left) == 0:
        return right

    if len(right) == 0:
        return left

    result = []
    index_left = index_right = 0

    while len(result) < len(left) + len(right):
        if left[index_left] <= right[index_right]:
            result.append(left[index_left])
            index_left += 1
        else:
            result.append(right[index_right])
            index_right += 1

        if index_right == len(right):
            result += left[index_left:]
            break

        if index_left == len(left):
            result += right[index_right:]
            break
    return result


def mergeSort(self, arr):
    """ mergeSort Algorithm Implementation in Python 3

        arr : Unorded list
        output : Return list in ascending order.
        time complexity : O(n log2n)
        Note : O(n log2n) is the best possible worst-case runtime that can be
        achieved by a sorting algorithm.

        Example :
        >>> mergeSort([4,2,6,5,9,8])
        [2, 4, 5, 6, 8, 9]"""

    if len(arr) < 2:
        return arr

    midpoint = len(arr) // 2

    return merge(left=mergeSort(arr[:midpoint]),
                 right=mergeSort(arr[midpoint:]))
