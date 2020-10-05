#include <bits/stdc++.h>
using namespace std;

//Boruvkas_algorithm
//Prequisite = Disjoint Set Union Data Structure

/*Boruvka's Algorithm focuses on reducing the number of component in each iteration by atleast half.
That is why, this algorithm works in O(Elog(V)) Time.

In each iteration, we select the lost weight outgoing edge for each component and then unite these 2 components using Disjoint Set Union Data Strucutre.
Initially there are V components. ( Each vertex is the only element in their own component).
When total_component reaches 1, that means only 1 component (i.e MST) is present.
*/


//Initialising DSU structure.
struct dsu{
	int *parent;
	int *rank;
	void init(int n){
		parent = new int[n];
		rank = new int[n];
		for(int i=0;i<n;++i){
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x){
		if(parent[x]==x) return x;
		return parent[x] = find(parent[x]); //Path compression.
	}
	void unite(int x,int y){
		int supx = find(x);
		int supy = find(y);
		if(supx!=supy){
			if(rank[supx]>rank[supy]){ // Rank compression.
				parent[supy] = supx;
			}
			else{
				parent[supx] = supy;
			}
		}
		else{
			parent[supy] = supx;
			rank[supx]++;
		}
	}
};


int main(){
  int n;
  int edge[1000][1000];
  cout<<"Enter the number of vertices"<<endl;
  cin>>n;
  cout<<"Enter the weight matrix "<<endl;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      cin>>edge[i][j]; //edge[i][j] represent the weight of the edge between vertix i and j
    }
  }
  dsu ds;
  ds.init(n);
  int ans = 0;
	int total_component = n;
	while(total_component>1){
		pair<int,int> lowest[n];
		for(int i=0;i<n;++i)
			lowest[i].first = INT_MAX;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				int supy = ds.find(j);
				int supx = ds.find(i);
				if(supx==supy)
					continue;
				int w = edge[i][j];
				if(lowest[supy].first > w){
					lowest[supy].first = w;
					lowest[supy].second = supx;
				}
				if(lowest[supx].first > w){
					lowest[supx].first = w;
					lowest[supx].second = supy;
				}
			}
		}
		for(int i=0;i<n;++i){
			if(ds.find(i)==i){
				int edge_to = ds.find(lowest[i].second);
				int w = lowest[i].first;
				if(i!=edge_to){
					ans += w;
					ds.unite(i,edge_to);
					total_component--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
