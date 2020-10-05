// DFS
#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define fi first
#define se second
using namespace std;

class Graph{
    private:
        map<int, vector<int> > m;
        vector<bool> visited(1000000, false);
    public:
        // add Edges to the graph, to get an undirected graph
        void add_Edge(int a, int b){
            m[a].pb(b);
            m[b].pb(a);
        }

        // print graph
        void printGraph(){
            for(auto it:m){
                cout << it.fi << ": ";
                for(auto i:it.se) cout << i << " ";
                cout << "\n";
            }
        }

        // iterative dfs(using stack )
        void dfs_iterative(int src){
            stack<int> s;
            s.push(src);
            vector<bool> vis(1000, false);
            vis[src] = true;
            while(!s.empty()){
                int p = s.top();
                s.pop();
                for(int i:m[p]){
                    if(!vis[i]){
                        cout << i << " ";
                        vis[i] = true;
                        s.push(i);
                    }
                }
            }
            cout << "\n";
        }

        // recursive dfs
        void dfs_recursive(int src){
            visited[src] = true;
            for(int i: m[src]){
                if(!visited[i]){
                    cout << i << " ";
                    dfs_recursive(i);
                };
            }
        }   
};


int main(){
    Graph g;
    g.add_Edge(0, 1);
    g.add_Edge(2, 1);
    g.add_Edge(0, 3);
    g.add_Edge(2, 3);
    g.add_Edge(3, 4);
    g.add_Edge(4, 5);

    //g.printGraph();
    g.dfs_recursive(0);
}
