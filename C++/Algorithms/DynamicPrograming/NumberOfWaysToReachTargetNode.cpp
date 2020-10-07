//AnkitCode99 here....
// Contributed to - Py-Contributors/AlgorithmsAndDataStructure

/*

Given a directed acyclic graph with N nodes and M edges. Starting from 
node number 1 find the number of ways to reach node T(i.e., the target node).

*/


#include<bits/stdc++.h>
#define endl "\n"
#define Ryuga ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

ll n,m,target;
vector<ll> ar[sz];
ll dp[sz];
bool vis[sz];

ll moves(ll node,ll par)
{
	if(node==target)
		return 1;
	
	ll ways=0;
	for(ll x:ar[node])
	{
		if(x!=par)
			ways+=moves(x,node);
	}
	return dp[node]=ways;
}

int main()
{
	Ryuga;

	#ifndef ONLINE_JUDGE
	freopen("IP.txt","r",stdin);
	freopen("OP.txt","w",stdout);
	#endif

	clock_t startTime=clock();

	cin>>n>>m;
	rep(i,0,m)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].pb(b);
	}



	cin>>target;

	cout<<moves(1,-1)<<endl;

	// This way not only not 1, you can see the number of ways to
	// reach target node starting from any node other than 1
	// rep(i,1,n+1)
	// {
	// 		cout<<dp[i]<<" ";
	// }

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...


/*

Sample Input
7 9
1 2
1 4
2 3
2 5
4 5
4 6
3 5
6 5
5 7
7

Sample Output
4

Time Complexity - O(N)
Space Complexity - O(N)

where, N = number of nodes in the graph

*/