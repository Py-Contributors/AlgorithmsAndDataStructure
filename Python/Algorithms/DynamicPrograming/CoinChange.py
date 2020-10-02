import sys
def coinChange(coins, m, V):
    '''
        Find minimum number of coins required to make a change.
    '''
    table = [0]
    # initialize value:
    for i in range(V+1):
        table.append(sys.maxsize)

    for i in range(1, V+1):
        for j in range(m):
            coin = coins[j]
            if coin <= i:
                table[i] = table[i-coin] + 1 if table[i-coin] + 1 < table[i] else table[i]
    return table[V]

if __name__ == '__main__':
    V = int(input("Enter value: "))
    coins = list(map(int, input("Enter coins: ").split()))
    print(coinChange(coins, len(coins), V))