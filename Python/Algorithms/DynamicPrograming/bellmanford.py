class Graph:
    # initialiser for grpah class to initialise graph to blank 
    def __init__(self,vertices):
        # V = number of vertices
        self.V=vertices
        # blanck graph
        self.graph=[]

    def AddEdge(self,u,v,w):
        # Adding edge from u to v with weight w into graph
        self.graph.append([u,v,w])
    
    def _PrintGraph(self,dist):
        print("Distance:")
        # printing distance for each vertices
        for i in range(self.V):
            print("%d \t\t %d "%(i,dist[i]))
    
    def BellmanFord(self,src):
        # 
        dist=[float("Inf")]*self.V 
        # init distance from source to source = 0 
        dist[src]=0
        # Accesing each edge from graph
        for u,v,w in self.graph:
            # changing distance for iterating for each edge if it is less than previous distance from u to v
            if dist[u] != float("Inf") and dist[u]+w<dist[v]:
                dist[v]=dist[u]+w
        for u,v,w in self.graph:
            # detecting negative cycle. Negatve cycle exits when after looping above loop also their is condition that distance is currently less
            if dist[u] != float("Inf") and dist[u]+w<dist[v]:
                print("Graph contains negative cycle!!")
                # return
        # if no negative cycle exits, printing each distance.
        self._PrintGraph(dist)
       
# test code 
vertices=int(input("Enter number of vertices:\n"))
edges=int(input("Enter number of edges:\n"))
g=Graph(vertices)
for i in range(edges):
    u=int(input("Source vertex:\n"))
    v=int(input("Destination vertex:\n"))
    w=int(input("weight of Edge:\n"))
    g.AddEdge(u,v,w)
g.BellmanFord(0) 