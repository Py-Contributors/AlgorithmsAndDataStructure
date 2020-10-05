/*
Finding Articulation Points and bridges using Tarjan's Algorithm.

DFS Tree: Tree formed as a result of DFS while not visiting
		  the already visited nodes
Backedge: Edge that points to already visited nodes
Discovery Time: First time, a node was visited.
Lowest time(n) = min(backedge from n,
				 backedge from any of child nodes of n)

Articulation point
Lowest Time[child] >= Disc[parent]
Bridge:
Lowest Time[child] > Disc[parent]
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 100005, M = 22;
#define int long long int
vector<int>  gr[N];
vector<int> art_p;
vector<pair<int, int>> bridge;
int disc[N], low[N], tme;


void dfs(int cur, int par) {
	disc[cur] = low[cur] = tme++;
	for (auto child : gr[cur]) {
		//not visited
		if (disc[child]) {
			dfs(child, cur);
			low[cur] = min(low[cur], low[child]);
			if (low[child] >= disc[cur] and par != 0)
			{
				//art point
				art_p.pb(cur);
			}
			if (low[child] > disc[cur])
			{
				//bridge
				bridge.pb({cur, child});
			}
		}

		else if (child != par) {

			//backedge
			//cycle  found
			low[cur] = min(low[cur], disc[child]);
		}
	}

}



int32_t main() {

	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n >> m;
	for ( i = 0; i < m; i++) {

		int x; int y;
		gr[x].pb(y);
		gr[y].pb(x);

	}
	dfs(1, 0);
}
