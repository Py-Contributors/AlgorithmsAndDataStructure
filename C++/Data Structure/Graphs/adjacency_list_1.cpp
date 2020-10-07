// Graph Representation with Adjaency list
#include<bits/stdc++.h>

using namespace std;

class Graph{
        int v;
        // Array of list
        list<int> *l;  
    public: 
        Graph(int v){ //constructor
            this->v = v;
            l = new list<int>[v];
        }

        void addEdge(int x, int y){ // adding bidirectional edges
            l[x].push_back(y); 
            l[y].push_back(x);
        }

        void printAdjList(){
            //Iterate over all the vertices
            for(int i=0; i<v; i++){
                cout << "Vertex" <<i<< "->";
                for(int j:l[i]){
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();

}