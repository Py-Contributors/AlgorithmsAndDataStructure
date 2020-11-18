/*
Count the number of connected components by DFS Traversal.

The idea here:
(i) We will start the DFS traversal from any node, say 'src' of the graph and mark all the nodes connected directly
     or indirectly to this node(src) visited.
(ii) After that we will check which node is not visited and we will call DFS traversal on it.
(iii) The count of connected components will be the number of DFS traversals called.
*/
/*
Sample Problem for Practice: https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/description/
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005; // defining the maximum size of the graph
vector<int> adjList[maxn];
bool visited[maxn];

void DFS(int node)
{
	visited[node] = true; // marking the current node visited
	for (auto child : adjList[node])
	{
		if (visited[child] == false) // calling DFS only on those nodes which are not visited
		{
			DFS(child);
		}
	}
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	for (int i = 0, u, v; i < edges; i++)
	{
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	int src; // source vertex from where the DFS traversal will start
	cin >> src;

	int connected_components = 0;
	for (int i = 1; i <= nodes; i++)
	{
		if (visited[i] == false)  // Calling DFS on those nodes which are not visited
		{
			DFS(i);
			connected_components++;
		}
	}
	cout << "The Number of Connected Components are " << connected_components << "\n";
	return 0;
}

/*
Input:
9 8
1 2
2 3
3 9
9 1
4 5
4 6
5 6
7 8

Output:
The Number of Connected Components are 3
*/

