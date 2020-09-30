//C++
//Implement the longest Common subsequence of three sequences in C++
#include<bits/stdc++.h>
using namespace std;
int lcs(int X[],int Y[],int Z[],int n,int m,int o)
{
    int t[n+1][m+1][o+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            for(int k=0;k<o+1;k++)
            {
                if(i==0 || j==0 || k==0)
                t[i][j][k]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            for(int k=1;k<o+1;k++)
            {
                if(X[i-1]==Y[j-1] && X[i-1]==Z[k-1])
                t[i][j][k]=1+t[i-1][j-1][k-1];
                else
                t[i][j][k]=max(max(t[i-1][j][k],t[i][j-1][k]),t[i][j][k-1]);
            }
        }
    }
    return t[n][m][o];
}
int main()
{
    int n1;
    cin>>n1;
    int a[n1];
    for(int i=0;i<n1;i++)
    cin>>a[i];
    int n2;
    cin>>n2;
    int b[n2];
    for(int i=0;i<n2;i++)
    cin>>b[i];
    int n3;
    cin>>n3;
    int c[n3];
    for(int i=0;i<n3;i++)
    cin>>c[i];
    cout<<lcs(a,b,c,n1,n2,n3);
}