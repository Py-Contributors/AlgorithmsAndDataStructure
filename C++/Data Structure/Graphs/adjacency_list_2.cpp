// Graph representation using hash maps(Adjacency list)
// used for both directed and undirected graphs
#include<iostream>
#include<unordered_map>
#include<list>


using namespace std;

class Graph{
    unordered_map<string, list<pair<string, int>>> umap;
    public:
        // x and y are nodes, they can be of any datatype, here string is taken
        // a is to decide whether it is directed or unidirected
        // b is to assign weights to the edges
        void addEdge(string x, string y, bool a, int b){
            umap[x].push_back(make_pair(y, b)); // here make_pair is important
            if(a){
                umap[y].push_back(make_pair(x, b));
            }
        }
        
        // to print the graph
        void show(){
            for(auto x: umap){
                cout << x.first << "->";
                for(auto y: x.second){
                    cout << y.first << ", " << y.second << endl;
                }
            }
        }
};


int main(){
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "D", false, 50);
    g.addEdge("A", "C", true, 10);
    g.show();
}

