def maxProduct(nums):
    n = len(nums)

    ans = nums[0]
    maxy = mini = ans
    for i in range(1, n):

        if nums[i] < 0:
            maxy, mini = mini, maxy

        maxy = max(nums[i], maxy * nums[i])
        mini = min(nums[i], mini * nums[i])

        ans = max(ans, maxy)

    return ans


if __name__ == '__main__':
    ans = maxProduct([2, 3, -2, 4])
    assert ans == 6, 'Wrong answer'
    print(ans)
