from PIL import Image
import numpy as np

def imagetoarray(filename):
    img=Image.open(filename).convert('RGBA')
    arr=np.array(img)
    return arr.flatten()

def lcs(X , Y):

    m = len(X)
    n = len(Y)

    L = [[None]*(n+1) for i in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0 :
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1]+1
            else:
                L[i][j] = max(L[i-1][j] , L[i][j-1])
    index = L[m][n]
    lcs_algo = [""] * (index+1)
    lcs_algo[index] = ""

    i = m
    j = n
    while i > 0 and j > 0:

        if X[i-1] == Y[j-1]:
            lcs_algo[index-1] = X[i-1]
            i -= 1
            j -= 1
            index -= 1

        elif L[i-1][j] > L[i][j-1]:
            i -= 1
        else:
            j -= 1

    # Printing the sub sequences
    print("The lcs common subsequence is : ")
    print(lcs_algo)

    return L[m][n]

a1=imagetoarray("final1.png")
a2=imagetoarray("img2.png")
totalLength=len(a2)
finalLength=lcs(a1,a2)
percent=(finalLength/totalLength)*100
percent=round(percent,2)
print("The two image are",percent,"% similar")
