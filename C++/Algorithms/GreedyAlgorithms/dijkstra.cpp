#include <iostream>

using namespace std;

int miniDist(int distance[], bool Tset[],int m,int n) // finding minimum distance
{
    int minimum=INT_MAX,ind;

    for(int k=0;k<m;k++)
    {
        if(Tset[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int m, int n,int graph[][20],int src) // adjacency matrix
{
    int distance[m]; // // array to calculate the minimum distance for each node
    bool Tset[n];// boolean array to mark visited and unvisited for each node


    for(int k = 0; k<m; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0;   // Source vertex distance is set 0

    for(int k = 0; k<m; k++)
    {
        int mn=miniDist(distance,Tset,m,n);
        Tset[mn]=true;
        for(int k = 0; k<m; k++)
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[mn][k] && distance[mn]!=INT_MAX && distance[mn]+graph[mn][k]<distance[k])
                distance[k]=distance[mn]+graph[mn][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<m; k++)
    {
        char str=65+k;
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()

{ int m,n;
cin>>m>>n;
    int graph[20][20];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    DijkstraAlgo(m,n,graph,0);
    return 0;
}
