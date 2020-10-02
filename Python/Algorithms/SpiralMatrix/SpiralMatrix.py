def spiral_matrix():
    i = 0  # starting row index
    j = 0  # starting column index
    c = 0
    print("Please enter number of rows of the spiral matrix:")
    try:
        no = int(input())
    except Exception:
        print("Please enter numbers only")
        return 0
    high = no ** 2
    val = 1
    a = [[0 for i in range(no)] for j in range(no)]

    while val <= high:
        while j < no - 1:  # for first row
            a[i][j] = val
            val += 1
            j += 1
        while i < no - 1:  # for last column
            a[i][j] = val
            val += 1
            i += 1
        while j > c:  # for last row
            a[i][j] = val
            val += 1
            j -= 1
        while i > c:  # for first column
            a[i][j] = val
            val += 1
            i -= 1
        no -= 1
        i += 1
        j += 1
        c += 1
        if val == high:  # for odd matrix size
            a[i][j] = val
            break
    print("Spiral matrix is:")
    for row in a:
        print(row)


spiral_matrix()
