"""
- COIN CHANGE
- Given coins of different denominations and a total amount of money, this function computes the fewest number of coins needed to make up that amount.
  If that amount of money cannot be made up by any combination of the coins, it returns -1.
- Bottom-up dynamic programming is used.
"""

# 'coins' is an array of different denominations
# 'amount' is the total amount of money
def coinChange(coins, amount) -> int:
    dp = [float('inf') for i in range(amount + 1)]    # dp array to store least number of coins for different amounts
    dp[0] = 0
    for i in range(1, len(dp)):
        for coin in coins:
            if i >= coin and (i - coin) != float('inf'):    # if it is possible to reach this amount with given denominations of coins
                dp[i] = min(dp[i], dp[i - coin] + 1)
    if dp[-1] == float('inf'):    # impossible to reach this amount with given denominations of coins
        return -1
    return dp[-1]

print(coinChange([1,2,5], 11))    # prints 3