#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;     //n represents the nth stair where a person wants to go
	cin>>n;
	int i;
    vector<int>A(n+1,0);
    A[0]=1;
    for(i=1;i<=n;i++)
    {
        A[i]+=A[i-1];   //number of ways from the previous step 
        if(i>1)
        A[i]+=A[i-2];   // number of ways from the (current step-2)th step
    }
    cout<<A[n]<<endl;
	return 0;
}
