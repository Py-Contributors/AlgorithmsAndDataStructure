/*
    Kosaraju Algorithm - 
    Given a directed graph, the 
    algorithm computes all the
    strongly connected components
    Time Complexity - O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

// declaring global variables
vector<vector<int>> edges, edgesT;
vector<bool> visited;
stack<int> s;
int n, e;

// This dfs call is on original graph to
// fill the stack
void dfs1(int start)
{
    visited[start] = true;
    for (int u : edges[start])
    {
        if (!visited[u])
        {
            dfs1(u);
        }
    }
    s.push(start);
}

// This dfs call is on transpose
// of original graph to find
// strongly connected components
void dfs2(int start)
{
    visited[start] = true;
    cout << start << " ";
    for (int u : edgesT[start])
    {
        if (!visited[u])
        {
            dfs2(u);
        }
    }
}

void kosaraju()
{
    // Unvisiting all vertices
    visited.assign(n, false);

    // Filling stack with the correct vertices
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

    // Unvisiting all vertices
    visited.assign(n, false);

    // Finding all the strongly connected components
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        if (!visited[v])
        {
            dfs2(v);
            cout << endl;
        }
    }
}

int main()
{
    // We make 2 graphs :-
    // 1. The original graph
    // 2. The transpose of original graph
    cin >> n >> e;
    edges.assign(n, vector<int>());
    edgesT.assign(n, vector<int>());
    visited.assign(n, false);
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edgesT[v].push_back(u);
    }

    // Calling kosaraju
    kosaraju();
    return 0;
}