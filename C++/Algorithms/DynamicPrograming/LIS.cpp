#include<bits/stdc++.h> 
using namespace std; 

int lis(int arr[], int n){
    int i = 0, j = 0 ;
    int ans[n]; 
    ans[0] = 1; 
    for(int i = 1; i<n ; i++){
        ans[i] = 1; 
        for(int j = 0; j<i; j++){
            if(arr[i]>arr[j] && ans[i] <ans[j]+1){
                ans[i] = ans[j]+1; 
            }
        }
    }
    return *max_element(ans, ans+n) ;
}
int main() {
	int t; cin>>t ;
	while(t--){
	    int n ; cin>>n; 
	    int arr[n] ;
	    for(int i = 0; i<n ; i++){
	        cin>>arr[i];
	    }
	    cout<<lis(arr,n)<<endl;
	}
	return 0;
}
