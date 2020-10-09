'''
Shortest Common Supersequence

Problem: Given two strings S1 and S2, find the length of shortest string that
has both S1 and S2 as subsequences.
Eq:
Input:   S1 = "AGGTAB", S2 = "GXTXAYB"
Output:  "AGXGTXAYB"
'''


def shortest_common_supersequence(str1, str2):
    ''' Return the length of shortest string that has both str1 and str2
     as subsequence '''

    def lcs(str1, str2, n, m):
        ''' Return the length of least common subsequence between str1 and
            str2. '''

        # Create a cache to hold lcs values for str lengths i and j
        cache = [[0] * (m + 2) for i in range(n + 2)]
        # Fill values in cache in bottom up manner.
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if str1[i - 1] == str2[j - 1]:
                    # case: the characters at ends of str1 and str2 are same
                    cache[i][j] = 1 + cache[i - 1][j - 1]
                else:
                    # case: the characters at ends of str1 and str2 are
                    # different
                    cache[i][j] = max(cache[i][j - 1], cache[i - 1][j])
        # We want to know the length of lcs for complete length of str1
        # and str2, hence, return appropriate cache value corresponding to
        # length n and m
        return cache[n][m]

    if None in [str1, str2]:
        return 0
    # Length of str1
    n = len(str1)
    # Length of str2
    m = len(str2)
    # get lcs of these two strings
    l_lcs = lcs(str1, str2, n, m)
    # The string with maximum length that is a supersequence is simply a
    # concatenated string on str1 and str2. The lcs is the string that will
    # occur twice in this maximum length superstring ie s1+s2. In order to
    # get the length of shortest supersequence, we just delete one set of lcs.
    # The string that is left after this operation is the Shortest Common
    # Supersequence. Return its length
    return m + n - l_lcs


if __name__ == '__main__':
    print('Enter two strings:')
    s1 = input('string 1: ')
    s2 = input('string 2: ')
    print(shortest_common_supersequence(s1, s2))
