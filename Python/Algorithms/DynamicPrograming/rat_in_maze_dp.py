"""
    Problem Discription:
        Given a grid find no of ways to reach from 0,0 to r-1,c-1

    Implimentation:
     maze = [[0, 0, 0, 0], 
            [0, -1, 0, 0], 
            [-1, 0, 0, 0], 
            [0, 0, 0, 0 ]] 
    print(getWays(maze)) 

    Negative values means Blocking

"""


R = 5  ## No of Rows
C = 5  ## No of Columns

def getWays(maze): 
    if (maze[0][0] == -1): 
        return 0 
    for i in range(R): 
        if (maze[i][0] == 0): 
            maze[i][0] = 1
        else: 
            break
    for i in range(1, C, 1): 
        if (maze[0][i] == 0): 
            maze[0][i] = 1
        else: 
            break
    for i in range(1, R, 1): 
        for j in range(1, C, 1): 
            if (maze[i][j] == -1): 
                continue 
            if (maze[i - 1][j] > 0): 
                maze[i][j] = (maze[i][j] +
                              maze[i - 1][j])  
            if (maze[i][j - 1] > 0): 
                maze[i][j] = (maze[i][j] +
                              maze[i][j - 1]) 
    if (maze[R - 1][C - 1] > 0): 
        return maze[R - 1][C - 1]  
    else: 
        return 0