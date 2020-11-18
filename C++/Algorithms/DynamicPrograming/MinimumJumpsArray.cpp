#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &A) {
    int n=A.size(),maxval=0;
    vector<int> v(n,-1);
     v[0]=0;//Initialise starting index jump value to 0,because already it is at starting position
     for(int i=0;i<n;i++)
     {
         if(v[i]==-1)
           return -1;
         if(i+A[i]>=maxval)//If sum exceed maxval,change the values of indices exceeding the maxval till the sum should be changed and should be assigned 1+value at index i
         {
             for(int j=maxval+1;j<=min(n-1,i+A[i]);j++)
               v[j]=v[i]+1;
               maxval=i+A[i];//Keeping the track of maxval 
         }
     }
     return v[n-1];//Returning the finalval
}

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
     for(int i=0;i<n;i++)
     {
         cin>>A[i];
     }
     int val=minJumps(A);
       if(val==-1)
         cout<<"It's not possible to reach the end"<<endl;
        else
          cout<<"Min jumps required to reach the end is:"<<val<<endl;
}
