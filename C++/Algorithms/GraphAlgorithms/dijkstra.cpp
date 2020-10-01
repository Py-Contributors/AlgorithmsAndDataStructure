
// shortest path , Dijkstra Algorithm

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &dist,vector<bool> &visited){

	int min  = 99999;
	int index; // index to store min value


	for(int i = 0; i < (int)dist.size(); i++){
		if(dist[i] < min and visited[i] == false){
			min =  dist[i];
			index = i;
		}
	}

	if(min != 99999){
		return index;
	}
	else{
	
		return -1;
	}

}


void dijkstra(vector<vector<int> > graph,int src, int V){

	
	vector<bool> visited(V); 
	vector<int> dist(V);    // to store distance/weight

	for(int i = 0; i < V; i++){
		visited[i] = false;
		dist[i] = INT_MAX;
	}
	dist[src] = 0;


	while(1){
	

		int u  = findMin(dist,visited);
		if(u == -1){
			break;
		}

		
		for(int i  = 0; i < V; i++){
			if(graph[u][i]!=0 and visited[i] == false){
				int total = dist[u] + graph[u][i];
				if(total < dist[i]){
					dist[i] = total;
				}
			}
		}

		visited[u] = true;
	}

	for(int i = 0; i < V; i++){
		cout<<dist[i]<<" ";
	}
}


int main(){
	int V; cin>>V;
	int src; cin>>src;
	vector<vector<int> > graph(V);
	for(int i = 0; i < V; i++){
		graph[i].resize(V);
		for(int j = 0; j < V; j++){
			cin>>graph[i][j];
		}
	}
  
  // you can make graph via adj. matrix
	/*int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };  */

	dijkstra(graph,src,V);
}
