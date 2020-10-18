# Tim Sort Algorithm

"""
- Divide the array into blocks (varies from 32 to 64)
- Sort them using insertion sort one by one
- After sorting merge them.

"""

MIN_MERGE = 32


def minimum(n):
    r = 0
    while n >= MIN_MERGE:
        r |= n & 1
        n >>= 1
    return n + r


def insertion_sort(arr, left, right):
    for i in range(left + 1, right + 1):
        j = i
        while j > left and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1


def merge(arr, left, mid, right):
    left_half_size = mid - left + 1
    right_half_size = right - mid

    left_half, right_half = [], []

    for i in range(left_half_size):
        left_half.append(arr[left + i])

    for j in range(right_half_size):
        right_half.append(arr[mid + 1 + j])

    i = j = 0
    k = left

    # Merge the two arrays
    while i < left_half_size and j < right_half_size:
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1

        else:
            arr[k] = right_half[j]
            j += 1

        k += 1

    # Copy if there is any remaining elements left in each half
    while i < left_half_size:
        arr[k] = left_half[i]
        i += 1
        k += 1

    while j < right_half_size:
        arr[k] = right_half[j]
        j += 1
        k += 1


def tim_sort(arr):
    n = len(arr)
    min_run = minimum(n)

    # Sort subarrays if size min_run
    for start in range(0, n, min_run):
        end = min(start + min_run - 1, n - 1)
        insertion_sort(arr, start, end)

    # Merge from size min_run. Then increase the size to 64, 128 and so on ..
    size = min_run
    while size < n:
        for left in range(0, n, 2 * size):
            mid = min(n - 1, left + size - 1)
            right = min((left + 2 * size - 1), n - 1)
            merge(arr, left, mid, right)
        size = 2 * size


if __name__ == "__main__":
    print("Enter your array (values should be space separated):")
    arr = list(map(int, input().strip().split()))
    print("Input Array:", arr)
    tim_sort(arr)
    print("Sorted Array:", arr)
