class Kruskal:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = []
        
    def addEdge(self, src, dest, weight):
        self.graph.append([src, dest, weight])
       # self.graph.append([dest, src, weight])
        
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])
    
    def union(self, parent, rank, x, y): 
        xroot = self.find(parent, x) 
        yroot = self.find(parent, y) 
        if rank[xroot] < rank[yroot]: 
            parent[xroot] = yroot 
        elif rank[xroot] > rank[yroot]: 
            parent[yroot] = xroot 
        else : 
            parent[yroot] = xroot 
            rank[xroot] += 1
    
    def kruskalAlgorithm(self):
        result = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.vertices):
            parent.append(node)
            rank.append(0)
        while e < self.vertices - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.union(parent, rank, x, y) 
        for u, v, weight in result:
            print("%d - %d: %d" % (u, v, weight))

graphObj = Kruskal(4)

graphObj.addEdge(0,1,3)
graphObj.addEdge(1,3,10)

graphObj.addEdge(2,0,5)
graphObj.addEdge(1,2,15)

graphObj.kruskalAlgorithm()
print(graphObj.graph)

