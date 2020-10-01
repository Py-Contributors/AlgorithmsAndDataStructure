#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


template <typename T>
class Graph {
	map<T, list<T>> m;
public:
	void addEdge(T x, T y) {
		m[x].push_back(y);
		m[y].push_back(x);
	}
	void dfs_helper(T src, map<T, bool> &visited) {
		cout << src << ",";
		visited[src] = true;
		for (auto neigh : m[src]) {
			if (!visited[neigh]) {
				dfs_helper(neigh, visited);
			}
		}
	}
	void dfs(T src) {
		map<T, bool> visited;
		// Mark all the nodes in graph as unvisited i.e false
		for (auto p : m) {
			T node = p.first;
			visited[node] = false;
		}
		dfs_helper(src, visited);
	}
};
int main() {
	init();
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.dfs(0);
	return 0;
}
