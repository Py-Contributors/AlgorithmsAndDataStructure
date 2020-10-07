#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int counter =0;
void generator(string s,int n){
	counter++;
	int j = 0;
	while(n>0){
		int lsb = (n&1);
		if(lsb){
			cout<<s[j];
		}
		j++;
		n>>=1;
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    cin.ignore();
    int l = s.length();
    // 1<<l as there will be 8 subsets
    for(int i=0;i<(1<<l);i++){
		generator(s,i);	
		cout<<endl;
	}
	cout<<counter<<endl;
    
    return 0;
}