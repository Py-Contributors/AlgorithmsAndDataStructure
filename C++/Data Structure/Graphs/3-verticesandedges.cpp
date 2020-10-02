#include <iostream>
#include<bits/stdc++.h>
using namespace std;
pair<int,int> vecount(int **graph, int v, int sv, bool *visited){
    if(v==0){
        return make_pair(0, 0);
    }
    int vcount =0;
    int ecount =0;
    queue<int> q;
    q.push(sv);
    visited[sv] =true;
    vcount++;
    while(!q.empty()){
        int fron = q.front();
        q.pop();
        visited[fron] = true;
        for(int i=0;i<v;i++){
            if(i== fron)
            continue;
          if(graph[fron][i] == 1 && !visited[i]){
              ecount++;
              vcount++;
              visited[i] = true;
              q.push(i);
          }
        }
    }
    pair<int,int> p;
    p.first=vcount;
    p.second=ecount;
    return p;
}
pair<int,int> count(int **graph, int v){
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] =0;
    }
    pair<int,int> P;
    pair<int,int> ans;
    ans.first=0;
    ans.second=0;
    for(int i=0;i<v;i++){
        if(visited[i] == 0){
            P=vecount(graph, v, i, visited);
            ans.first += P.first;
            ans.second += P.second;
        }
    }
    return ans;
   
    
}
int main() {
    int V, E;
    cin >> V >> E;
    int** graph=new int*[V];
    for(int i=0;i<V;i++){
        graph[i]=new int[V];
        for(int j=0;j<V;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }
    pair<int,int> P ;
    P.first=0;
    P.second=0;
    P= count(graph, V);
    if(P.first%2 == 0){
        cout<<"No. of vertices are even: "<<P.first<<endl;
    }
    else{
        cout<<"No. of vertices are odd: "<<P.first<<endl;
    }
   
   cout<<"No. of edges: "<<P.second<<endl; 
    
	// your code goes here
	return 0;
}
