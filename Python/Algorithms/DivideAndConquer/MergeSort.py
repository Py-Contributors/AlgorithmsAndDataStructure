from typing import List


def merge(left: List[int], right: List[int]) -> List[int]:
    """Merges two sorted lists into a single sorted list.

    Args:
        left (list): The left half of the list to be merged.
        right (list): The right half of the list to be merged.

    Returns:
        list: The sorted list resulting from merging the left and right halves.
    """
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


def merge_sort(unsorted_list: List[int]) -> List[int]:
    """Sorts a list of integers using the merge sort algorithm.

    Args:
        unsorted_list (list): The unsorted list to be sorted.

    Returns:
        list: The sorted list.
    """
    if len(unsorted_list) < 2:
        return unsorted_list

    midpoint = len(unsorted_list) // 2

    return merge(left=merge_sort(unsorted_list[:midpoint]),
                 right=merge_sort(unsorted_list[midpoint:]))

