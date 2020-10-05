def issubset(set, n, sum):
    subset = ([[False for i in range(sum + 1)]for i in range(n + 1)])
    for i in range(0, n + 1):
        subset[i][0] = True
    for i in range(0, n + 1):
        for j in range(0, sum + 1):
            if j >= set[i - 1]:
                subset[i][j] = subset[i - 1][j] or subset[i - 1][j - set[i - 1]]

    return(subset[n][sum])


# __main__
a = int(input("Enter the number of elements in the set: "))
arr = []
for i in range(0, a):
    arr.append(int(input('Enter the element one at a time: ')))
s = int(input("Enter the desired sum: "))
if (issubset(arr, len(arr), s) is True):
    print('Their exist a subset with the sum:', s)
else:
    print('No subset exist with the sum:', s)
