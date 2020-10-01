//by @chaupatt (ajayjha5899 on Github)
#include<bits/stdc++.h>

using namespace std;

/*
    Kadane's Algorithm is used to find the max sum subarray
    within a given array.
*/
int kadanesAlgorithm(vector<int> a){
    int n = a.size();

    int sum = 0, maxx = 0;
    for(int i=0; i<n; i++){
        sum = max(a[i],sum+a[i]);
        maxx = max(maxx, sum);
    }

    if(maxx==0){
        sort(a.begin(),a.end());
        maxx = a[n-1];
    }

    return maxx;
}

signed main(){
    vector<int> a{1,3,2,4,5,-1,4,-30,-20,1,4,3};
    int ans = kadanesAlgorithm(a);
    cout << "Max subarray sum = " << ans << "\n";
    return 0;
}