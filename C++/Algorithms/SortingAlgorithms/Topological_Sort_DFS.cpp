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


    void dfshelper(T node, map<T, bool> &visited, list<T>&ordering) {
        // comes to the node, mark it as visited
        visited[node] = true;


        for (T neighbour : adjList[node]) {
            if (!visited[neighbour]) {
                dfshelper(neighbour, visited, ordering);
            }
        }
        ordering.push_front(node);





    }

    void dfs_topological() {
        map<T, bool>visited;
        list<T> ordering;
        for (auto i : adjList) {
            T node = i.first;
            if (!visited[node]) {
                dfshelper(node, visited, ordering);
            }

        }
        for (auto element : ordering) {
            cout << element << "-->";
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
    cout << "Depth First Search Topological Sort Applied:" << endl;
    g.dfs_topological();
    cout << endl;


    return 0;
}




