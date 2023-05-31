def countingSort(array):
    """
    Implements the counting sort algorithm on an input array of integers.

    Args:
    - array: A list of integers to be sorted.

    Returns:
    - A list of integers sorted in non-descending order.

    Time Complexity:
    - O(n + k), where n is the length of the input array and k is the range of values in the input array.

    Space Complexity:
    - O(k), where k is the range of values in the input array.
    """

    # determine the maximum value in the input array
    n = max(array) + 1

    # initialize a count array of size n with all elements set to 0
    count = [0] * n

    # iterate over the input array and increment the count of each element's value
    for i in array:
        count[i] += 1

    # modify the count array to reflect the number of elements <= each element's value
    for i in range(1, n):
        count[i] += count[i - 1]

    # create a result array of size len(array) with all elements set to 0
    result = [0] * len(array)

    # iterate over the input array backwards and place each element in its sorted position in the result array
    for i in range(len(array) - 1, -1, -1):
        result[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1

    # return the sorted result array
    return result

def main():
    # define an example array to sort
    array = [3, 1, 7, 4, 9, 2, 6, 5, 8, 0]

    # sort the array using countingSort
    sorted_array = countingSort(array)

    # print the sorted array
    print(sorted_array) # expected output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

if __name__ == "__main__":
    main()
