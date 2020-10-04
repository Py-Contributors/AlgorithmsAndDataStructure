def interpolationSearch(arr, lo, hi, x):
    if (lo <= hi and x >= arr[lo] and x <= arr[hi]):
        # Probing the position with keeping
        # uniform distribution in mind.
        pos = lo + ((hi - lo) // (arr[hi] - arr[lo]) * (x - arr[lo]))
        # Condition of target found
        if arr[pos] == x:
            return pos
        # If x is larger, x is in right subarray
        if arr[pos] < x:
            return interpolationSearch(arr, pos + 1, hi, x)
        # If x is smaller, x is in left subarray
        if arr[pos] > x:
            return interpolationSearch(arr, lo, pos - 1, x)
    return - 1


arr = [10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47]
n = len(arr)
x = 18
index = interpolationSearch(arr, 0, n - 1, x)
if index != -1:
    print("Element found at index", index)
else:
    print("Element not found")
