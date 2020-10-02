
def binarySearch(A, left, right, x):

    if left > right:
        return -1
    mid = (left + right) // 2
    if x == A[mid]:
        return mid

    elif x < A[mid]:
        return binarySearch(A, left, mid - 1, x)
    else:
        return binarySearch(A, mid + 1, right, x)


def exponentialSearch(A, x):

    bound = 1
    while bound < len(A) and A[bound] < x:
        bound *= 2
    return binarySearch(A, bound // 2, min(bound, len(A)), x)


if __name__ == '__main__':

    A = [2, 5, 6, 8, 9, 10]
    key = 9

    index = exponentialSearch(A, key)

    if index != -1:
        print("Element found at index", index)
    else:
        print("Element found not in the list")
