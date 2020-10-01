#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll replace(ll n,ll m, int i, int j){
	int maskclr = (n&(((-1)<<(j+1))|((1<<i)-1)));
	int maskshf = m<<i;
	return maskshf|maskclr;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n = 15;
    ll m = 2;
    int i=1,j=3;
    ll ans = replace(n,m,i,j);
    cout<<ans<<endl;
    return 0;
}