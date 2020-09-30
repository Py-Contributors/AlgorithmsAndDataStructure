def lcs(s1,s2):
    dp = [[0]*(len(s2)+1)]*(len(s1)+1)
    print(dp)
    maxi = 0
    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i] == s2[j]:
                dp[i+1][j+1] = 1 + dp[i][j]
            else:
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
            maxi = max(maxi, dp[i+1][j+1])
    print(maxi)

lcs('ABC','AE')