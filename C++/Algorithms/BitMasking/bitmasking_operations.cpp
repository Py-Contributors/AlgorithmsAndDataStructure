#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// For getting pth bit
int getbit(int n,int p){
	int mask = (n&(1<<p));
	int bit = mask>0?1:0;
	return bit;
}
// Setting pth bit
int setbit(int n, int p){
	int mask = (n|(1<<p));
	return mask;
}
// clr pth bit
void clrbit(int &n, int p){
	n = (n&(~(1<<p)));
}

int upbit(int &n, int p, int val){
	clrbit(n,p);
	n = (n|(val<<p));
}
// -1 or ~0 = 11111111111 all set bits

// clear bit at pth pos
int clrlbit(int n, int p){
	int mask = (n&((-1)<<(p+1)));
	return mask;
}

// Clear bit in range fp to lp
int clrbitrange(int n, int fp, int lp){
	// or 2^i - 1
	int mask = (n&(((-1)<<(fp+1))|(~((-1)<<(lp+1)))));
	return mask;
}
// set number
int setno(int n){
	int c = 0;
	while(n>0){
		(n&1)?c++:c+=0;
		n>>=1;
	}
	return c;
}

// Counter for set bits
int setbitcountfast(int n){
	int c = 0;
	while(n>0){
		n=n&(n-1);
		c++;
	}
	return c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<getbit(10,1)<<endl;
    cout<<setbit(10,2)<<endl;
    int n=10;
    clrbit(n,1);
    cout<<n<<endl;
    n = 14;
    upbit(n,2,0);
    cout<<n<<endl;
    cout<<clrlbit(15,2)<<endl;
    cout<<clrbitrange(63,3,1)<<endl;
    cout<<setno(63)<<endl;
    cout<<__builtin_popcount(63)<<endl;
    cout<<setbitcountfast(63)<<endl;
    return 0;
}