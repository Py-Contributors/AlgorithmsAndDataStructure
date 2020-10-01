#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template <typename T>
class Graph {
	// unweighted graph
	map<T, list<T>> m;
public:
	void addEdge(T x, T y) {
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void bfs(T src) {
		map<T, int> visited;
		queue<T> q;
		q.push(src);
		visited[src] = true;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << ",";
			for (auto neigh : m[node]) {
				if (!visited[neigh]) {
					q.push(neigh);
					// mark that neigh as visited
					visited[neigh] = true;
				}
			}
		}
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
	// 0 is the src node
	g.bfs(0);
	return 0;
}
