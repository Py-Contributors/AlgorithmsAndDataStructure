#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int dtobint(int n){
	int ans= 0,p=1;
	while(n>0){
		int lsbit = (n&1);
		ans+=p*lsbit;
		p*=10;
		n>>=1;
	}
	return ans;
}
string dtob(int n){
	string a = "";
	while(n>0){
		if(n&1){
			a.append("1");
		}else{
			a.append("0");
		}
		n>>=1;
	}
	reverse(a.begin(),a.end());
	return a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    cout<<dtob(n)<<endl;
    cout<<dtobint(n)<<endl;
    return 0;
}