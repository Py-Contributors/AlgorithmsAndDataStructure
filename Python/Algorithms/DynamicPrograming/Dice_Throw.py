# Given n dice with f number of faces and an integer x.
# We have to find the number of ways to get sum X when all the dice are thrown at a time.


def solve(d, f, s):
    # Creating a table for storing the results of subproblems.
    dp = [[0 for i in range(s + 1)] for j in range(d)]
    # As the row represent the number of dice and column represent the sum
    # So the first row will be filled with 1 upto min of faces and sum.
    for j in range(1, min(s + 1, f + 1)):
        dp[0][j] += 1
    for i in range(1, d):
        for j in range(1, s + 1):
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j - 1]
            # It can go upto sum - faces - 1
            if j - f - 1 >= 0:
                dp[i][j] -= dp[i - 1][j - f - 1]
    # The value of the last sell will represent the maximum number of ways to get the Sum X.
    return dp[-1][-1]


d = 3
f = 4
X = 5
print(solve(d, f, X))
