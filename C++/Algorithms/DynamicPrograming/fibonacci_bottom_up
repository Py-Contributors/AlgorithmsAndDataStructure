//In the bottom-up dynamic programming approach, we’ll reorganize the order in which we solve the subproblems
//This will allow us to use less memory space in our code.
#include <iostream>
using namespace std;

//space O(n)
int fib(int n,int dp[]){
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

//space O(1)
int fib_Space_Opt(int n){
	//base case
	if(n == 0 || n == 1) return n;

	int a = 0;
	int b = 1;
	int c;

	for(int i=2;i<=n;i++){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}


int main() {
 int n;
 cout<<"Enter number 'n' to find nth fibonacci number: ";
 cin>>n;
 int dp[n+1]={0};
 dp[1] = 1;

 cout<<"Output calculated with space complexity O(n): ";
 cout<<fib(n,dp)<<endl;
 cout<<"Output calculated with space complexity O(1): ";
 cout<<fib_Space_Opt(n)<<endl;

return 0;
}

/*
sample input output
input: 10
output: 55
*/

/*
Time O(n)
*/
