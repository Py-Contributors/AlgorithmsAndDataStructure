# Implementation of Naive Pattern Searching in Python3
# pat -> pattern, txt -> given text
def search(pat, txt):

    # get lengths of pattern and text
    M = len(pat)
    N = len(txt)

    # go through pat[]
    for i in range(N - M + 1):
        j = 0
        # For current index i, check for pattern match
        while(j < M):
            if (txt[i + j] != pat[j]):
                break
            j += 1

        if (j == M):
            print("Found pattern at index: ", i)
# output: Found pattern at index 0, 4, 8


# Driver Code
txt = "ABACABBDABA"
pat = "AB"
search(pat, txt)
