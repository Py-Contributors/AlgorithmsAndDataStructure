# Implementation of Kruskal's Algorithm for Minimum Spanning Trees
# Author: Nick Rodriguez

class Edge:
    def __init__(self, weight: int, node1: int, node2: int):
        self.weight = weight
        self.node1 = node1
        self.node2 = node2


class Graph:
    def __init__(self, edge_list, num_of_vertices: int):
        self.edge_list = edge_list
        self.num_of_vertices = num_of_vertices
        self.spanning_tree = []
        self.parent = [None] * self.num_of_vertices
        self.rank = [0] * self.num_of_vertices

    def find(self, node):
        if node == self.parent[node]:
            return node
        else:
            return self.find(self.parent[node])

    def displayGraph(self, graph):
        print("\n * Input Edges: \n")
        print("\t * Weight of (Node1 <-> Node2)\n")

        for x in self.edge_list:
            print("\t\t", x.weight, "==", x.node1, "<->", x.node2)

    def displayMST(self, tree):
        cost = 0

        print("\n * Edges of MST: \n")
        print("\t * Weight of (Node1 <-> Node2)\n")

        for y in self.spanning_tree:
            print("\t\t", y.weight, "==", y.node1, "<->", y.node2)
            cost = cost + y.weight

        print("\n\t * Cost = ", cost, "\n")

    def Kruskal(self):

        self.displayGraph(self)

        self.edge_list.sort(key=lambda Edge: Edge.weight)  # yes

        for i in range(self.num_of_vertices):
            self.parent[i] = i

        for x in self.edge_list:
            start_root = self.find(x.node1)
            end_root = self.find(x.node2)

            if start_root != end_root:

                self.spanning_tree.append(x)

                if self.rank[start_root] >= self.rank[end_root]:
                    self.rank[start_root] = self.rank[start_root] + 1
                    self.parent[end_root] = start_root
                else:
                    self.rank[end_root] = self.rank[end_root] + 1
                    self.parent[start_root] = end_root

        self.displayMST(self.spanning_tree)

# Used this Wiki Commons image of a completed MST using Krustal's Algorithm
# https://commons.wikimedia.org/wiki/File:Kruskal_Algorithm_6.svg

print('''
============== Kruskal's algorithm ==============


* Rough Sketch of Graph:
    * In the code node A = 0, B = 1, etc.
    


        (A) - 7 - (B) -- 8 -- (C)
         |      /    \        /
         5    9       7     5
         |  /          \  /
        (D) --- 15 --- (E)
           \          /   \ 
            6       8      9
              \   /         \ 
               (F) -- 11 -- (G)

''')



e1 = Edge(7, 0, 1) # a_b
e2 = Edge(5, 0, 3) # a_d
e3 = Edge(9, 1, 3) # b_d
e4 = Edge(8, 1, 2) # b_c
e5 = Edge(7, 1, 4) # b_e
e6 = Edge(5, 2, 4) # c_e
e7 = Edge(15, 3, 4) # d_e
e8 = Edge(6, 3, 5) # d_f
e9 = Edge(8, 4, 5) # e_f
e10 = Edge(11, 5, 6) # f_g
e11 = Edge(9, 4, 6) # e_g


original_list = [e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11]

g1 = Graph(original_list, 7)
g1.Kruskal()
