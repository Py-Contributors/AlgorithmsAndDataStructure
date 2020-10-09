//kandane algorithm
//very important algoritm from interview perspective
//many interview problems are either based directly on kandane algorithm or modifies kandane algorithm
//goal is to find a subarry with maximum possible sum(basic kandane)

#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> vec{10,2,-3,3,-8,10,15};
	//let the maximum sum be stored in variable named maxi
	int maxi=INT_MIN;
	//let the current sum be stored in the variable named currsum
	int currsum=0;
	//kandane algorithm 
	for(auto it:vec){
		currsum+=it;
		maxi=max(currsum,maxi);
		if(currsum<0) currsum=0;
	}
	cout<<maxi<<endl;
	//similarly question can be twisted to find the starting and ending index of the subarray with maximum sum
}