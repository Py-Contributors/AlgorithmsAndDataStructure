# This is Python Dynamic programming implementation of the
# Longest Common Subsequence Problem, built in bottom up fashion.
# Give 2 strings A and B, this program finds the length
# if the longest common subsequence
# Dynamic Programming implementation of LCS problem


def longestCommonSubsequence(A, B):
    # storing lengths
    n = len(A)
    m = len(B)

    # declaring the array L for storing the dp values
    L = [[None] * (m + 1) for i in range(n + 1)]

    # Note: L[i][j] contains length of LCS of A[0..i-1] and B[0..j-1]
    for i in range(n + 1):
        for j in range(m + 1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif A[i - 1] == B[j - 1]:
                L[i][j] = L[i - 1][j - 1] + 1
            else:
                L[i][j] = max(L[i - 1][j], L[i][j - 1])

    # L[n][m] contains the length of LCS of A[0..m-1] & B[0..n-1]
    return L[n][m]


# end of function lcs

if __name__ == "__main__":
    A = "HEYTHERE"
    B = "HELLOTHERE"
    ans = longestCommonSubsequence(A, B)
    print(ans)
