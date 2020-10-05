
// BFS
#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define fi first
#define se second
using namespace std;


class Graph{
    private:
        map<int, vector<int> > m;
        int size;
    public:
    	Graph(int size){
    		this->size = size;
    	}
        // adding edges to the graph, forming a undirected graph
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

        // simple bfs
        void bfs(int src){
            queue<int> q;
            q.push(src);
            map<int, bool> visited;
            visited[src] = true;
            while(!q.empty()){
                for(int i:m[q.front()]){
                    if(!visited[i]){
                        cout << i << " ";
                        q.push(i);
                        visited[i] = true;
                    }
                }
                q.pop();
            }
        }

        // to find level of each node
        // returns a list whose index are elements of the graph
        // and value corresponding to the index denotes the level for that element
        vector<int> levelOrder(int src){
            vector<int> level(size+1);
            queue<int> q;
            q.push(src);
            map<int, bool> visited;
            visited[src] = true;
            level[src] = 0;
            while(!q.empty()){
                int p = q.front();
                q.pop();
                for(int i:m[p]){
                    if(!visited[i]){
                        level[i] = level[p]+1;
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            for(int i:level) cout << i << " ";
            return level;
        }
};

int main(){
    Graph g(5);
    g.add_Edge(0, 1);
    g.add_Edge(1, 2);
    g.add_Edge(2, 3);
    g.add_Edge(0, 3);
    g.add_Edge(3, 4);
    g.add_Edge(4, 5);

    g.printGraph();
    g.bfs(0);
}
