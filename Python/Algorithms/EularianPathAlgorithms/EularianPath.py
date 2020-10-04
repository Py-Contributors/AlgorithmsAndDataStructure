# Python3 program to find out Eulerian path
# It takes the adjacency matrix representation of the
# graph as input


def findpath(g):
    n = len(g)
    numOfAdj = list()

    # Finds the degree of each vertex.
    for i in range(n):
        numOfAdj.append(sum(g[i]))

    # Finds the number of vertices with odd degree
    start = 0
    numOfOdd = 0
    for i in range(n - 1, -1, -1):
        if numOfAdj[i] % 2 == 1:
            numOfOdd += 1
            start = i

    # If number of vertex with odd number of edges
    # is greater than two then eularian path doesn't exist
    if numOfOdd > 2:
        print("No Solution")
        return

    # Finding the path, if it exists:

    # Initialize empty stack and path
    stack = list()
    path = list()
    # take the starting current
    current = start

    # Loop runs if there is element in the stack
    # or current edge has some neighbour.
    while stack != [] or sum(g[current]) != 0:

        # If current node does not have any neighbour, then
        # add it to path and pop stack
        # set new current to the popped element
        if sum(g[current]) == 0:
            path.append(current + 1)
            current = stack.pop(-1)

        # If the current vertex has at least one
        # neighbour then add the current vertex to stack,
        # remove the edge between them and set the
        # current to its neighbour.
        else:
            for i in range(n):
                if g[current][i] == 1:
                    g[i][current] = 0
                    g[current][i] = 0
                    stack.append(current)
                    current = i
                    break
    # printing the path
    for element in path:
        print(element, "-> ", end="")
    print(current + 1)


# Driver Program
if __name__ == "__main__":
    g = [
        [0, 1, 0, 0, 1],
        [1, 0, 1, 1, 0],
        [0, 1, 0, 1, 0],
        [0, 1, 1, 0, 0],
        [1, 0, 0, 0, 0],
    ]
    ans = findpath(g)
    print(ans)
