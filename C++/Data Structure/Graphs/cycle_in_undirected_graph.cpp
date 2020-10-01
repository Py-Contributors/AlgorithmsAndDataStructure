#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int> adj[],vector<int>& vis,int parent){
  vis[node]=true;
  for(auto it:adj[node]){
    if(!vis[it]){
      if(dfs(it,adj,vis,node)){
        return true;
      }
    }
    else if(it!=parent){
      return true;
    }
  }
  return false;
}

int main(){
  //input number of vertices(n) and number of edges(e)
  int n,e;
  cin>>n>>e;
  vector<int> adj[n];//adjacency list

  vector<int>vis(n,0);//visited nodes

  for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  bool ans = dfs(0,adj,vis,-1); //depth first search to find cycle
  if(ans){
    cout<<"Cycle exist"<<"\n";
  }
  else{
    cout<<"Cycle doesn't exist"<<"\n";
  }
}