#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>adj[],bool vis[],bool *rec){
  if(vis[node]==false){
    vis[node]=true;
    rec[node]=true;

    for(auto it:adj[node]){
      if(!vis[it] and dfs(it,adj,vis,rec)){
        return true;
      }
      else if(rec[it]==true){
        return true;
      }
    }
  }
  rec[node]=false;
  return false;
}

int main(){
  int n,e;//input number of vertices(n) and number of edges(e)
  cin>>n>>e;
  vector<int> adj[n];//adjacency list
  bool visited[n]={false};// visited nodes
  bool rec[n]={false};// visited node in current dfs

   for(int i=0;i<e;i++){
     int u,v;
     cin>>u>>v;
     adj[u].push_back(v);
   }
   bool ans=false;
   for(int i=0;i<n;i++){
     if(!visited[i]){
       ans = dfs(i,adj,visited,rec);//depth first search to find cycle 
       if(ans==true){
          break;
       }
     }
   }
   if(ans){
   cout<<"Cycle exist";
   }
   else{
     cout<<"Cycle doesn't exist";
   }
   cout<<"\n";
}