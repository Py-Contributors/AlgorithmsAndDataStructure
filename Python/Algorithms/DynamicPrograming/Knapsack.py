# memoization approach of 0 / 1 Knapsack in Python
# recursion + memoization


# utility function
def knapsack(wt, val, W, n):
    # base cases
    if n == 0 or W == 0:
        return 0
    if t[n][W] != -1:
        return t[n][W]

    # choice diagram
    if wt[n - 1] <= W:
        t[n][W] = max(
            val[n - 1] + knapsack(
                wt, val, W - wt[n - 1], n - 1),
            knapsack(wt, val, W, n - 1))
        return t[n][W]
    elif wt[n - 1] > W:
        t[n][W] = knapsack(wt, val, W, n - 1)
        return t[n][W]


# driver code
if __name__ == "__main__":
    # test params
    val = [60, 100, 120]
    wt = [10, 20, 30]
    W = 50
    n = len(val)

    # Initialize the matrix with -1 at first.
    t = [[-1 for i in range(W + 1)] for j in range(n + 1)]
    print(knapsack(wt, val, W, n))
