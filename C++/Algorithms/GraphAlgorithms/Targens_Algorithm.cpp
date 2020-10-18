/**  Articulation Point and Bridges | Targen's_Algorithm.cpp **/

#include<bits/stdc++.h>
using namespace std;
#define MAX 11

vector<int> adj[MAX];
bool vis[MAX];
int disc[MAX];
int low[MAX];
int parent[MAX];
int n;
int count_of_AP;
int count_of_bridges;
set<int> AP;
set< pair<int,int> > B;

void init()
{
    for(int i = 0; i <= n; i++)
    {
        disc[i] = 0;
        low[i] = INT_MAX;
        vis[i] = false;
        parent[i] = -1;
    }
}

void Articulation_points(int ver)
{
    static int c = 0;

    vis[ver] = true;

    disc[ver] = low[ver] = c++;

    int child = 0;
    for(int i = 0; i < adj[ver].size(); i++)
    {
        if( ! vis[ adj[ver][i] ])
        {
            child++;

            parent[ adj[ver][i] ] = ver;

            Articulation_points( adj[ver][i] );

            low[ver] = min( low[ver] , low[ adj[ver][i] ] );

            if( parent[ver] == -1 and child > 1)
            {
                AP.insert(ver);
            }

            if( parent[ver] != -1 and low[ adj[ver][i] ] >= disc[ver] )
            {
                AP.insert(ver);
            }
        }
        else if( adj[ver][i] != parent[ver] )
        {
            low[ver] = min( low[ver] , disc[ adj[ver][i] ]);
        }
    }

}

void bridge(int x)
{
    static int c = 0;
    vis[x] = true;
    disc[x] = low[x] = c++;

    for(int i = 0; i < adj[x].size(); i++)
    {
        if( ! vis[ adj[x][i] ])
        {
            parent[adj[x][i]] = x;

            bridge(adj[x][i]);

            low[x] = min(low[x],low[ adj[x][i] ]);

            if( low[ adj[x][i] ] > disc[ x ])
            {
                if( adj[x][i] > x)
                {
                    B.insert( {x , adj[x][i]} );
                }
                else
                {
                    B.insert( {adj[x][i] , x} );
                }
            }
        }
        else if(parent[x] != adj[x][i])
        {
            low[x] = min( low[x] , disc[ adj[x][i] ] );
        }
    }
}

int main()
{
    int m;

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    count_of_AP = 0;
    init();
    AP.clear();
    Articulation_points(1);
    count_of_AP = AP.size();
    cout << count_of_AP << endl;
    for(auto i : AP)
        cout << i << ' ';

    cout << endl;

    count_of_bridges = 0;
    init();
    B.clear();
    bridge(1);
    count_of_bridges = B.size();
    cout << count_of_bridges << endl;
    for(auto i : B)
    {
        cout << i.first << ' ' << i.second << endl;
    }
}
