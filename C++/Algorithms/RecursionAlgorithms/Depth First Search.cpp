#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int mxN = 1e5;
vector<int>adj[mxN];
bool visited[mxN];

void createEdge(int x,int y)
{
    adj[x].pb(y);
    adj[y].pb(x);
}

void dfs(int s)
{
    cout<<s<<" ";
    visited[s] = true;

    for(int i = 0; i < adj[s].size(); i++)
    {
        if(!visited[adj[s][i]])
            dfs(adj[s][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nodes,edges;
    cin>>nodes>>edges;

    //create undirected graph

    for(int i = 0; i < edges; i++)
    {
        int x,y;
        cin>>x>>y; //nodes

        createEdge(x,y);
    }

    //nodes are numbered from 1 to N

    for(int i = 1; i <= nodes; i++)
    {
        if(!visited[i])
            dfs(i);
    }

    cout<<endl;

    return 0;
}