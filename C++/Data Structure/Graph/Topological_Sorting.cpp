// C++ implementation of Topological Sorting

/* 
Topological sorting of vertices/nodes of a Directed Acyclic Graph is an linear 
ordering of the vertices/nodes v1,v2,v3....  in such a way, that if there is an edge
directed towards vertex/node vj from vertex vi, then vi comes before vj. 

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int NoOfNodes,NoOfEdges,a,b;
	
	// result is vector which contains the topological sorting of graph.
	vector<int> result;
	
	// Enter the Number of Nodes that graph contains and the number of edges.
	cin>>NoOfNodes>>NoOfEdges;
	
	// arr is the array vector to store the graph as a adjacency list.
	vector<int> arr[NoOfNodes];
	
	// indegree contains the number of indegree edge on particular node.
	int indegree[NoOfNodes]={0};
	
	// For loop that input the edges from user with source to destination.
	for(int i=0;i<NoOfEdges;i++){
		cin>>a>>b;
		arr[a].push_back(b);
		indegree[b]++;
	}
	
	// queue which store only those nodes which have indegree zero. 
	queue<int> q;
	
	for(int i=0;i<NoOfNodes;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int current = q.front();
		result.push_back(current);
		q.pop();
		
		for(int node : arr[current]){
			indegree[node]--;
			if(indegree[node] == 0){
				q.push(node);
			}
		}
	}
	
	// If the result size is not equal to Number of nodes that means this graph contains a cycle because of which
	// the indegree of those nodes which made cycle never be zero. So, the topological sorting of those graph is not
	// possible. 
	if(result.size() == NoOfNodes){
		cout<<"Topological Sorting of this Graph is : ";
		for(int node : result){
			cout<<node<<" ";
		}
	}
	else{
		cout<<"Topological Sorting of this Graph is not possible because this graph contain Cycle."<<endl;
	}
}




