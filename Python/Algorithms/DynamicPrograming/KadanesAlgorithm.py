# To find the contiguous sub-array with the largest sum
# in a one-dimensional array of numbers

def kadane(nums):

    current_max = global_max = nums[0]

    for i in range(1, len(nums)):

        current_max = max(nums[i], nums[i] + current_max)

        if current_max > global_max:
            global_max = current_max

    return global_max


if __name__ == '__main__':
    print(kadane([-2, -3, -1, -5]))             # Output: -1
    print(kadane([-2, 1, -3, 4, -1, 2, 1, -5, 4]))   # Output: 6
