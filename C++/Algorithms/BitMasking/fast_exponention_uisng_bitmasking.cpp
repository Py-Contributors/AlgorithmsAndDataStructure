#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int fastexpo(int a,int b){
	int res = 1;
	while(b>0){
		if(b&1){
			res*=a;
		}
		a*=a;
		b>>=1;
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int p;cin>>p;
    int ans = fastexpo(t,p);
    cout<<ans<<endl;
    return 0;
}