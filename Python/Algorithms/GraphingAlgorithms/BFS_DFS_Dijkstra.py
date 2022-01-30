from queue import Queue
from queue import LifoQueue


'''
Simple implementation of a graph class
that encompasses unweighted/weighted and
directed/undirected graphs

Uses a dictionary of dictionaries to represent
the adjacency list.

EXAMPLE
1 is connected to 2 with weight 5
3 is connected to 1 with weight 10
Adjacency List:
{
1: {2:5, 3:10},
2: {1:5},
3: {1:10}
}
'''


class Graph:
    def __init__(self, directed=False):
        self.adjList = {}
        self.directed = directed

    def addEdge(self, _from, to, weight=1):
        if _from not in self.adjList.keys():
            self.adjList[_from] = {to: weight}
            if not self.directed:
                if to not in self.adjList.keys():
                    self.adjList[to] = {_from: weight}
                else:
                    self.adjList[to][_from] = weight
            if self.directed and to not in self.adjList.keys():
                self.adjList[to] = {}

        else:
            if to in self.adjList[_from].keys():
                print('Edge already exists!')
            else:
                self.adjList[_from][to] = weight
                if not self.directed:
                    if to not in self.adjList.keys():
                        self.adjList[to] = {_from: weight}
                    else:
                        self.adjList[to][_from] = weight
                if self.directed and to not in self.adjList.keys():
                    self.adjList[to] = {}

    def hasEdge(self, _from, to) -> bool:
        if _from in self.adjList.keys() and to in self.adjList[_from].keys():
            return True
        else:
            return False

    def hasVertex(self, vertex) -> bool:
        return vertex in self.adjList.keys()

    def getEdge(self, _from, to) -> int:
        if not self.hasEdge(_from, to):
            return -1
        else:
            return self.adjList[_from][to]

    def pathLength(self, path):
        sum = 0
        for i in range(0, len(path) - 1):
            sum += self.getEdge(path[i], path[i + 1])
        return sum

    def __str__(self):
        output = ''
        for node in self.adjList.keys():
            output += str(node) + ' : ' + str(self.adjList[node]) + '\n'
        return output


'''
Breadth-first search implemented using
sets, dictionaries, and queues.
All neighboring vertices are visited
and then their neighbors, etc. until
the destination has been found
'''


def BFS(graph, source, destination):
    visited = set()
    previous = {}
    queue = Queue()

#   start the search at the source
    previous[source] = source
    visited.add(source)
    queue.put(source)

    while not queue.empty():
        currNode = queue.get()

        for neighbor in graph.adjList[currNode].keys():
            if neighbor == destination:
                previous[neighbor] = currNode

#               construct the path list
                path = [destination]
                traceBack = currNode
                while not traceBack == source:
                    path.append(traceBack)
                    traceBack = previous[traceBack]
                path.append(source)

#               reverse the path so it goes from source to destination
                path.reverse()
                return path

#           if the neighbor in question has not been visited yet,
#           put it in the queue and update visited and previous
            if neighbor not in visited:
                previous[neighbor] = currNode
                visited.add(neighbor)
                queue.put(neighbor)

#   if the end of the queue is reached without finding the source,
#   there is no path from source to destination
    return []


'''
Depth-first search implemented using
sets, dictionaries, and queues.
Functionally the same as BFS, but uses a stack
to determine the next vertex to visit
Visit nodes down a path until there are no more to
vist. Then back up the path until it finds more.
'''


def DFS(graph, source, destination):
    visited = set()
    previous = {}
    stack = LifoQueue()

    previous[source] = source
    visited.add(source)
    stack.put(source)

    while not stack.empty():
        currNode = stack.get()

        for neighbor in graph.adjList[currNode].keys():
            if neighbor == destination:
                previous[neighbor] = currNode

#               construct the path list
                path = [destination]
                traceBack = currNode
                while not traceBack == source:
                    path.append(traceBack)
                    traceBack = previous[traceBack]
                path.append(source)

#               reverse the path so it goes from source to destination
                path.reverse()
                return path

#           if the neighbor in question has not been visited yet,
#           put it in the stack and update visited and previous
            if neighbor not in visited:
                previous[neighbor] = currNode
                visited.add(currNode)
                stack.put(neighbor)

#   if the end of the stack is reached without finding the source,
#   there is no path from source to destination
    return []


'''
Dijkstra's Algorithm implemented using
dictionaries and sets. This will find the
shortest path between any two nodes based
on their weights
'''


def Dijkstras(graph, source, destination):

    # put all nodes infinitely far away from
    # the source except the source itself
    shortest = {}
    for node in graph.adjList.keys():
        shortest[node] = float("inf")
    shortest[source] = 0

    previous = {}
    needsProcessing = set(graph.adjList.keys())

    while not len(needsProcessing) == 0:
        # get a random node from needsProcessing and replace it
        closest = needsProcessing.pop()
        needsProcessing.add(closest)

#       Find the closest node that still needs processing
        for node in needsProcessing:
            if(shortest[closest] > shortest[node]):
                closest = node

#       if a neighbor is accessed quicker through the closest node
#       instead of their current path, make its current path through
#       the closest node
        for neighbor in graph.adjList[closest].keys():
            edgeWeight = graph.adjList[closest][neighbor]
            if(shortest[neighbor] > shortest[closest] + edgeWeight):
                shortest[neighbor] = shortest[closest] + edgeWeight
                previous[neighbor] = closest

        needsProcessing.remove(closest)

#   construct the path list
    path = []
    traceBack = destination
    while not traceBack == source:
        path.append(traceBack)
        traceBack = previous[traceBack]
    path.append(source)

#   reverse the path so it goes from source to destination
    path.reverse()
    return path


# Example program to demonstrate functionality
def main():
    graph = Graph()
    graph.addEdge(1, 2, weight=7)
    graph.addEdge(1, 3, weight=9)
    graph.addEdge(1, 6, weight=14)
    graph.addEdge(2, 3, weight=10)
    graph.addEdge(2, 4, weight=16)
    graph.addEdge(3, 4, weight=11)
    graph.addEdge(3, 6, weight=2)
    graph.addEdge(4, 5, weight=6)
    graph.addEdge(5, 6, weight=9)
    print(graph)
    path = BFS(graph, 1, 5)
    print(path)
    print(graph.pathLength(path))
    print(DFS(graph, 4, 6))
    print(Dijkstras(graph, 2, 5))


if __name__ == "__main__":
    main()
