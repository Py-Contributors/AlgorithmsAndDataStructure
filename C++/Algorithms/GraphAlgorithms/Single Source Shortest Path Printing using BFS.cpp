/*
Problem:
We are given a undirected graph and a source vertex (say 'src'). We have to find the minimum distance between
the source vertex and a given destination vertex(say 'dest'). We also have to print the shortest path.
*/

/*
(i) The idea here is to use BFS for calculating the shortest distance.
(ii) We will maintain the parent node of every node with the help of which we can print the
shortest path.
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V; // Number of nodes in the graph
    list<int> *adjList;
public:
    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V + 1];
    }
    void addEdge(int u, int v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (int node : adjList[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void bfs(int src, int dest) // standarf BFS algorithm
    {
        queue<int> q;
        bool *visited = new bool[V] {0}; // To maintain the visited nodes
        int *dist = new int[V + 1] {0};  // To maintain the minimum distance of node from src node
        int *parent = new int[V + 1] {0}; // To keep parent node of every node

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (int x : adjList[node])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                    dist[x] = dist[node] + 1;
                    parent[x] = node;
                }
            }
        }
        cout << endl;
        ///Printing distance of every node from src
        for (int i = 0; i < V; i++)
        {
            cout << i << " node distance is: " << dist[i] << endl;
        }
        cout << endl;
        cout << "Shortest distance is " << dist[dest] << endl;
        cout << "Shortest path is ";
        int temp = dest;
        while (temp != -1)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 3);
    ///g.printAdjList();
    g.bfs(0, 5);
    return 0;
}
