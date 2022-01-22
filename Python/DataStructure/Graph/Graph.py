"""
Simple implementation of unweighted and weighted Graphs.

Both are implemented using adjacency lists.
The weighted graph implementation stores the target edges of a single
starting node of the adjacency list using a list of tuples (index, weight).

Example:
    >>> graph = WeightedGraph(5) # directed weighted graph
    >>> graph.add_edge(0, 1, weight=4)
    >>> graph.add_edge(0, 2, weight=3)
    >>> graph.add_edge(2, 3, weight=1)
    >>> graph.add_edge(3, 4, weight=5)
    >>> graph.add_edge(4, 1, weight=2)
    >>> print(graph)
    0: 1 (weight: 4) 2 (weight: 3)
    1:
    2: 3 (weight: 1)
    3: 4 (weight: 5)
    4: 1 (weight: 2)

    This example input is equivalent to:
    >>> graph.edges = [
    >>> [(1, 4), (2, 3)],
    >>> [],
    >>> [(3, 1)],
    >>> [(4, 5)],
    >>> [(1, 2)]
    >>> ]
    >>>
"""


class UnweightedGraph:
    def __init__(self, vertices, directed=True):
        self.vertices = vertices
        self.directed = directed
        self.edges = [[] for _ in range(vertices)]

    def __str__(self):
        output = ""

        for i in range(0, self.vertices):
            output += f"{i}: "

            for j in range(0, len(self.edges[i])):
                output += f"{self.edges[i][j]} "

            output += "\n"

        return output

    def has_vertex(self, vertex):
        return 0 <= vertex < self.vertices

    def has_edge(self, start, dest):
        if self.has_vertex(start) and self.has_vertex(dest):
            if dest in self.edges[start]:
                return True

        return False

    def add_edge(self, start, dest):
        if self.has_edge(start, dest):
            return False

        self.edges[start].append(dest)
        if not self.directed:
            self.edges[dest].append(start)

        return True


class WeightedGraph:
    def __init__(self, vertices, directed=True):
        self.vertices = vertices
        self.directed = directed
        self.edges = [[] for _ in range(vertices)]

    def __str__(self):
        output = ""

        for i in range(0, self.vertices):
            output += f"{i}: "

            for j in range(0, len(self.edges[i])):
                output += f"{self.edges[i][j][0]} "
                output += f"(weight: {self.edges[i][j][1]}) "

            output += "\n"

        return output

    def has_vertex(self, vertex):
        return 0 <= vertex < self.vertices

    def has_edge(self, start, dest, weight):
        if self.has_vertex(start) and self.has_vertex(dest):
            if (dest, weight) in self.edges[start]:
                return True

        return False

    def add_edge(self, start, dest, weight):
        if self.has_edge(start, dest, weight):
            return False

        self.edges[start].append((dest, weight))
        if not self.directed:
            self.edges[dest].append((start, weight))

        return True


def main():

    # Basic driver code to demonstrate functionality

    ugraph = UnweightedGraph(5)
    ugraph.add_edge(0, 1)
    ugraph.add_edge(0, 2)
    ugraph.add_edge(0, 3)
    ugraph.add_edge(2, 4)
    ugraph.add_edge(1, 2)
    print(ugraph)

    wgraph = WeightedGraph(5)
    wgraph.add_edge(0, 2, weight=3)
    wgraph.add_edge(0, 3, weight=2)
    wgraph.add_edge(1, 3, weight=4)
    wgraph.add_edge(2, 1, weight=1)
    wgraph.add_edge(4, 3, weight=6)
    print(wgraph)


if __name__ == "__main__":
    main()
