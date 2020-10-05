/*
## Lowest Common Anscestor for a Tree in C++

## what will change
create a trees folder in DS and add lca code to it.

## Problem

Given tree and n-1 edges.
Given two nodes a and b.
To find the lowest common ancestor of a and b in linear time.

input :
first line contains a single integer n - number of nodes
next n-1 lines x and y edges of the tree (0 < x,y <=n)
last line contains a(0 < a <= n) and b(0 < b <= n) - two nodes 

output:
print a single integer k which is the lowest common ancestor of a and b.


sample :
input:
```
9
1 2
1 3
1 4
2 5
2 6
3 7
5 9
6 8
9 6
```
output:
```
2
```
*/

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

class Tree{
	int n;// number of nodes
	list<int> *adj;
	vector<int> heights;// to store heights of tree
	vector<int> parents;// to store parents of each node
public:
	Tree(int n){
		this->n=n;
		adj=new list<int> [n];
		heights.assign(n,0);
		parents.assign(n,0);
	}

	void addEdge(int a,int b){
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	// depth first search to assign parent
	// because tree is an undirected graph with n-1 nodes
	// c is current node
	// p is parent node
	// h is the height
	void dfs(int c=0,int p=-1,int h=0){
		parents[c]=p;
		heights[c]=h;
		for(auto &x: adj[c]){
			if (x==p)continue;
			dfs(x,c,h+1);
		}
	}

	int lca(int a,int b){
		a--;b--;

		while (a!=b){
			// if height of a and height of b are at same height we pull both up
			if (heights[a]==heights[b]){
				a=parents[a];
				b=parents[b];
			}
			// if height a is greater we pull only a up
			else if(heights[a]>heights[b]){
				a=parents[a];

			}
			else{
				b=parents[b];
			}
		}

		return a+1;

	}

};


int main(){
	int n;
	cin >> n;

	Tree tr(n);
	for (int i = 0; i < n-1; ++i)
	 {
	 	int x,y;cin >> x >> y;
	 	tr.addEdge(x,y);
	 }


	int a,b;
	cin >> a >> b;
	tr.dfs();
	cout << tr.lca(a,b) << endl; 
}