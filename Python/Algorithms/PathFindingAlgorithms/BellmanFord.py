"""
Title - Bellman Ford Algorithm
Pupose - Finds the shortest path in a
         directed cyclic graph
         with no negative cycles
Time Complexity - O(VE)
"""
import math


class Graph:
    class Vertex:
        def __init__(self, vindex):
            self.parent = None
            self.dist = math.inf
            self.vindex = vindex

        def __repr__(self):
            return str(self.vindex)

    def __init__(self):
        self.vertices = set()
        self.edges = {}

    def add_vertex(self, v_index):
        v = self.Vertex(v_index)
        self.vertices.add(v)
        return v

    def add_edge(self, src, dest, weight):
        self.edges[(src, dest)] = weight

    def _relax_edge(self, src, dest):
        if dest.dist > src.dist + self.edges.get((src, dest), math.inf):
            dest.dist = src.dist + self.edges[(src, dest)]
            dest.parent = src

    def bellman_ford(self, source):
        source.dist = 0
        for i in range(len(self.vertices) - 1):
            for (src, dest) in self.edges:
                self._relax_edge(src, dest)

        for (src, dest) in self.edges:
            if dest.dist > src.dist + self.edges[(src, dest)]:
                return False
        return True

    def print_shortest_path(self, start, end):
        path = [end]
        if start == end:
            print(path)
        else:
            while end.parent:
                path.append(end.parent)
                end = end.parent
            if end == start:
                path.reverse()
                print(path)


# create a graph and add vertices
g = Graph()
v0 = g.add_vertex(0)
v1 = g.add_vertex(1)
v2 = g.add_vertex(2)
v3 = g.add_vertex(3)

# add edges and the corresponding weight
# example for a graph that can contains a simple shortest path
g.add_edge(v0, v3, 5)
g.add_edge(v0, v1, 1)
g.add_edge(v1, v2, 1)
g.add_edge(v2, v3, 1)

# example for a graph that does not contain a simple shortest path
# because there is a negative cycle
# g.add_edge(v0, v3, 5)
# g.add_edge(v0, v1, 1)
# g.add_edge(v1, v2, 1)
# g.add_edge(v2, v3, 1)
# g.add_edge(v3, v0, -10)

can_compute_shortest_path_for_g = g.bellman_ford(v0)
if can_compute_shortest_path_for_g:
    print('yes shortest path found!')
    g.print_shortest_path(v0, v3)
else:
    print('no shortest path')
