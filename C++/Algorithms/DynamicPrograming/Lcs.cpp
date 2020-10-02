//Dynamic Programming approach to the longest common subsequence
//Dynamic programming approach to the longest common subsequence
#include<bits/stdc++.h>
using namespace std;
int lcs(string X,string Y,int n,int m)
{
    //Initializing the two dimensional table
    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            t[i][j]=0;
        }
    }

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(X[i-1]==Y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[m][n];
}
//main 
int main()
{
    int n,m;
    string X,Y;
    cin>>n>>X>>m>>Y;
    cout<<lcs(X,Y,n,m);
}