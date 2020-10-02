#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int l[n];
for(int i=0;i<n;i++)
cin>>l[i];
int L;
cin>>L;
int t[n+1][L+1];
for(int i=0;i<=n;i++)
t[i][0]=1;
for(int i=1;i<=L;i++)
t[0][i]=0;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=L;j++)
  {
    if(l[i-1]>j)
    t[i][j]=t[i-1][j];
    else
    t[i][j]=t[i][j-l[i-1]]+t[i-1][j];
  }
}
cout<<t[n][L]<<endl;
}
