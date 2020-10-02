#include<bits/stdc++.h>
using namespace std;
int main() {
int V,E;
cin>>V>>E;
int** graph=new int*[V];
for(int i=0;i<V;i++){
graph[i]= new int[V];
for(int j=0;j<V;j++){
graph[i][j]=0;
}
}
for(int i=0;i<V;i++){
for(int j=0;j<V;j++){
int sv,ev,weight;
cin>>sv>>ev>>weight;
graph[sv][ev]=weight;
graph[ev][sv]=weight;
}
}
bool visited[V];
memset(visited, false, sizeof(visited));
int numOfEdge = 0,x,y;
visited[0] = true;
cout << "Edge"<< " : "<< "Weight"<<endl;
while (numOfEdge < V - 1) {
int min =INT_MAX;
x = 0;
y = 0;
for (int i = 0; i < V; i++) {
if (visited[i]) {

for (int j = 0; j < V; j++) {
if (!visited[j] && graph[i][j]) {
if (min > graph[i][j]) {
min = graph[i][j];
x = i;
y = j;
}
}
}
}
}
cout << x << " - " << y << " : " << graph[x][y]<<endl;
visited[y] = true;
numOfEdge++;
}
return 0;
}