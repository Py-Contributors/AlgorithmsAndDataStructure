#include<bits/stdc++.h> 
using namespace std; 

int func(int arr[], int n , int v){
    int dp[v+1]; 
    dp[0] = 0; 
    
    for(int i=1; i<=v; i++){
        dp[i] = INT_MAX; 
    }
    for(int i=1; i<=v; i++){
        for(int j=0; j<n ; j++){
            if(arr[j]<=i && dp[i-arr[j]] != INT_MAX){
                dp[i] = min(1+dp[i-arr[j]], dp[i]) ; 
            }
        }
    }
    int ans = dp[v] ; 
    if(ans ==INT_MAX){
        ans = -1; 
    }
    return ans; 
}
int main() {
	//code
	int t; 
	cin>>t; 
	while(t--){
	    int v, n ; 
	    cin>>v>>n; 
	    int arr[n] ; 
	    for(int i=0; i<n; i++){
	        cin>>arr[i]; 
	    }
	    cout<<func(arr,n,v)<<endl ; 
	}
	return 0;
}
