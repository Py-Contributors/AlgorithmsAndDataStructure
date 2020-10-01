#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph {
    map<T, list<T> > adjList;

public:
    Graph() {
    }

    void addEdge(T u, T v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }
    void print() {

        for (auto p : adjList) {
            auto key = p.first;
            auto neigbours = p.second; //list of neigbours

            cout << key << "->";
            for (auto n : neigbours) {
                cout << n << ",";
            }
            cout << endl;
        }
    }

    void bfs_topological() {
        queue<T>q;
        map<T, int>indegree;
        map<T, bool>visited;

        for (auto i : adjList) {
            auto node = i.first;
            visited[node] = false;
            indegree[node] = 0;

        }
        // initialise indegrees of all the nodes
        for (auto i : adjList) {
            auto u = i.first;
            for (auto v : adjList[u]) {
                indegree[v] += 1;
            }
        }
        // find out all nodes with zero indegree
        for (auto i : adjList) {
            auto node = i.first;
            if (indegree[node] == 0) {
                q.push(node);
            }
        }
        // starting with the algorithm
        while (!q.empty()) {
            auto node = q.front();
            cout << node << "-->";
            q.pop();

            for (auto neighbour : adjList[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }




    }
};


int main() {

    Graph<string>g;
    g.addEdge("English", "Programming logic", false);
    g.addEdge("English", "HTML", false);
    g.addEdge("Maths", "Programming logic", false);
    g.addEdge("Programming logic", "HTML", false);
    g.addEdge("Programming logic", "Python", false);
    g.addEdge("Programming logic", "Java", false);
    g.addEdge("Programming logic", "JS", false);
    g.addEdge("Python", "Web Development", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "JS", false);
    g.addEdge("JS", "Web Development", false);
    g.addEdge("Java", "Web Development", false);
    g.addEdge("Python", "Web Development", false);
    cout << "Adjacency list:" << endl;
    g.print();
    cout << "Breadth First Search Topological sort Applied:" << endl;
    g.bfs_topological();


    return 0;
}





















