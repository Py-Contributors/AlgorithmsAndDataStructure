#include <iostream>
using namespace std;
/*
Disjoint Set Union is extremely useful if we want to know the number of components in a graph, size of each components and 
whether 2 vertices are in same component or not in almost O(1) time. Disjoint is also useful for detecting cycles in the graph.
Each component is represented by a single vertex, sometimes called as superparent of that component. 
If superparent of 2 vertices are same, that means those 2 vertices are in same component.
*/
struct dsu
{
	int *par;
	int *size;
	int *edges;
	void init(int n){
		par = new int[n];
		size = new int[n];//gives total vertices in each component
		edges = new int[n];//gives total edges in each component
		for(int i=0;i<n;++i){
			par[i] = i;
			size[i] = 1;
			edges[i] = 0;
		}
	}
	int p(int x){
		if(par[x]==x) return x;
		return par[x] = p(par[x]);//Path Compression
	}
	void unite(int x,int y){
		int supx = p(x);
		int supy = p(y);
		if(supx!=supy){
			if(size[supx]>size[supy]){//Rank Compression
				par[supy] = supx;
				size[supx] += size[supy];
				edges[supx] += edges[supy]+1;
			}
			else{
				par[supx] = supy;
				size[supy] += size[supx];
				edges[supy] += edges[supx]+1;
			}
		}
		else{
			edges[supx]++;
		}
	}
};
int n,m,x,y;
/*
n -> number of vertices
m -> number of edges
unite(x,y) is used to create an edge between x and y or in other words, x and y are in same component
*/
int main(){
	cin>>n>>m>>x>>y;
	dsu d;
	d.init(n); //initializing the DSU
	for(int i=0;i<m;++i){
		cin>>x>>y;
		x--;y--;
		d.unite(x,y);//Uniting vertices x and y
	}
	return 0;
}
