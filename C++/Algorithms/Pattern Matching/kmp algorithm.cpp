//kmp algorithm
//This is a very popular algorithm in job interviews
//It helps to check whether a given array(character array(string) or normal array) is a subarray of another array or not
//This algorithm takes O(n) time
#include <bits/stdc++.h>

using namespace std;
//first we need to create an lps i.e "longest prefix that is also a suffix table also known as "pie table"
vector<int> generatelps(string s){
	vector<int> out(s.size());
	out[0]=0;
	int j=0;
	for(int i=1;i<s.size();i++){
		while(s[i]!=s[j] && j!=0){
			j=out[j-1];
		}
		if(s[i]==s[j]) j++;
		out[i]=j;
	}
	return out;
}
bool isfound(string mains,string checks){ // where 'mains' is the main string and 'checks' is the string we need to check
	vector<int> lps=generatelps(checks);
	int j=0;
	for(int i=0;i<=mains.size();i++){
		if(j==checks.size()){
			return true;
		}
		if(i==mains.size()) return false;
		while(mains[i]!=checks[j] && j!=0){
			j=lps[j-1];
		}
		if(mains[i]==checks[j]) j++;
	}
	return false;
}

int main(){
	string ii="piadfcadxcvas";
	string hh="piad";
	if(isfound(ii,hh)) cout<<1<<endl;
	else cout<<0<<endl;
}