#include <bits/stdc++.h>
using namespace std;

int main() {
     int n;
     cin>>n;
     int  a[n];
     int sum =INT_MIN,x;
     
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
         x+=a[i];
         sum=max(sum,x);
         x=max(x,0);
         
     }
     cout<<sum<<endl;
	// your code goes here
	return 0;
}
