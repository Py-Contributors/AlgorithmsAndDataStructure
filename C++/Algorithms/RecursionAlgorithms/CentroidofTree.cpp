#include <bits/stdc++.h>
using namespace std;
/*
Centroid of a Tree is a node which if removed from the tree would split it into a ‘forest’, 
such that any tree in the forest would have at most half the number of vertices in the original tree.
We use dfs algorithm to easily calculate the centroid of a tree.
A tree could have at most 2 centroid.
*/
unordered_map<int,vector<int>> l;
int n,m,x,y;
vector<int> centroid;
int *sz;
void dfs(int x,int prev){
	sz[x] =  1;
	bool iscentroid = true;
	for(auto i:l[x]){
		if(i!=prev){
			dfs(i,x);
			sz[x]+=sz[i];
			if(sz[i]>n/2){
				iscentroid = false;
			}
		}
	}
	if(n-sz[x] > n/2){
		iscentroid = false;
	}
	if(iscentroid){//if each subtree has nodes less then or equal to n/2, then only this node could be a centroid.
		centroid.push_back(x);
	}
}
int main(){
	cout<<"Enter the total nodes in the tree"<<endl;
	cin>>n;
	cout<<"Enter the edges in the tree"<<endl;
	//we are running the below loop n-1 times as a tree must have n-1 edges for each vertex to be connect to the order.
	//if the number of edges is greater then n-1, then a cycle must exist and hence it is not a tree
	//if the number of edges is less then n-1, then a tree of all the vertices cannot be formed.
	for(int i=0;i<n-1;++i){
		cin>>x>>y;
		x--;y--;
		l[x].push_back(y);
		l[y].push_back(x);
	}
	sz = new int[n];
	dfs(1,-1);
	//Every tree has atleast 1 centroid and atmost 2 centroid
	for(auto i:centroid){
		cout<<i+1<<" ";
	}
	return 0;
}
