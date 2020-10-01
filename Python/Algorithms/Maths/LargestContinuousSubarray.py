# Kadane's Algorithm
# Returns the largest sum in a contiguous subarray

def maxSubArray(a):

    curr_max = a[0]
    temp_max = a[0]

    for i in range(1, len(a)):
        temp_max = max(a[i], temp_max + a[i])
        curr_max = max(curr_max, temp_max)

    return curr_max


if __name__ == '__main__':
    print(maxSubArray([9, -2, 4, 7, -4, -8, 1, 6, -3]))
