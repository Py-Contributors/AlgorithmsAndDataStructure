#include<bits/stdc++.h>
using namespace std;

int adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    if(n==0)
      return -1;
    vector<int> dp(n,0);
    dp[0]=max(A[0][0],A[1][0]);
    if(n==1)
      return dp[0];
    dp[1]=max(A[0][1],A[1][1]);
    for(int i=2;i<n;i++)//For each index
    {
        dp[i]=max(A[0][i],A[1][i]);//Ith value will be maximum of two column values at ith index+maximum of the preceeding values with atleast an index difference of two
        int maxval=0;
        for(int j=i-2;j>=0;j--)//Checking for preceeding indices with differences of two
        {
            maxval=max(maxval,dp[j]);
        }
        dp[i]+=maxval;
    }
    int fmaxs=dp[0];
    for(int i=1;i<n;i++)//Finding maximum possible of each indices and returning the maxm possible value
    {
        fmaxs=max(fmaxs,dp[i]);
    }
    return fmaxs;
}

int main()
{
    int n;
    cin>>n;//Number of columns in 2d array
    vector<vector<int> > v(2,vector<int> (n,0));
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];//Taking inputs in row-wise order
        }
    }
    int temp=adjacent(v);
    if(temp==-1)
      cout<<"Vector is empty"<<endl;
     else
       cout<<temp<<endl;
       return 0;
}
