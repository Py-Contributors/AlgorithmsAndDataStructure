# This is a Dynamic Programming bottom-up implementation of Gold Mine Problem
# Given a gold mine of n*m dimensions.
# Intially the miner is at the first column but canbe at any column.
# It can move only right-up,right-down and right from thr given cell.
# We have to find the maximum amount of gold that can be collected.


def gold_mine(gold, m, n):
    # creating a table for storing intermediate results and intialize all cells to 0.
    # first row gives the maximum gold that the miner can collect when starts from that row.
    dp = [[0 for i in range(n)] for j in range(m)]
    for col in range(n - 1, -1, -1):
        for row in range(m):
            # Gold collected on going cell to the right
            if col == n - 1:
                right = 0
            else:
                right = dp[row][col + 1]
            # Gold collected on going cell to the right up
            if row == 0 or col == n - 1:
                right_up = 0
            else:
                right_up = dp[row - 1][col + 1]
            # Gold collected on going cell to the right down
            if row == m - 1 or col == n - 1:
                right_down = 0
            else:
                right_down = dp[row + 1][col + 1]
            # Max collected on choosing either of thr three path
            dp[row][col] += gold[row][col] + max(right_up, right, right_down)
    # Max Gold collected will be maximum value of the first column.
    res = dp[0][0]
    for i in range(1, m):
        res = max(res, dp[i][0])
    return res


gold = [[1, 3, 1, 5],
        [2, 2, 4, 1],
        [5, 0, 2, 3],
        [0, 6, 1, 2]]
m = 4
n = 4
print(gold_mine(gold, m, n))
