'''
    Author : @anushkrishnav
    Built using : networkx .
    It is a gold standard for Python DAGs (and other graphs).
    You can create a networkx directed graph with a list of tuples
    that represent the graph edges:
'''
import networkx as nx
from matplotlib import pyplot as plt


class DAG:

    def __init__(self):
        self.graph = nx.DiGraph()

    def addEdges(self, edges):
        """Function to add one edge at a time and
        check if the graph is acyclic post insertion"""
        self.graph.add_edge(edges)
        if nx.is_directed_acyclic_graph(self.graph):
            pass
        else:
            raise "Unable to insert " + str(edges) + "This is an Acyclic graph"
            self.graph.remove_edge(edges)

    def AddSetofEdges(self, listt):
        """Function to all a list of edges and
        check is the graph is an DAG for furthur details refer networkx"""
        self.graph.add_edges_from(listt)
        if nx.is_directed_acyclic_graph(self.graph):
            pass
        else:
            raise "This is an acyclic graph check your edges"
            self.graph.remove_edge(listt)

    def Visualise(self, location="home"):
        """It uses Matplotlib to visualise the DAG .
        The graph is stored in a PNG format . So name the file accourdingly
        eg
        >>> DAG.Visualise(home / img.png)"""
        if self.graph is None:
            return "There is no graph consider adding edges to visualise"
        plt.tight_layout()
        nx.draw_networkx(self.graph, arrows=True, node_size=800)
        plt.savefig(location, format="PNG")
        plt.clf()
        return "Graph generated"


graph = DAG()


graph.AddSetofEdges([("root", "a"), ("a", "b"),
                    ("a", "e"), ("b", "c"),
                    ("b", "d"), ("d", "e")])

graph.Visualise("Python/DataStructure/Graph/Dag.png")
