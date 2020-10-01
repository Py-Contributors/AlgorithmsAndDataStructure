#include <iostream>

using namespace std;

int fib(int n);


int memo[1000]; 

int main(){
		
	for(int i=0; i<100; i++){  		//initiate memo array with all zero values
		memo[i] = 0;
	}   
	
	cout << fib(9);
	
	return 0;
}

int fib(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	
	if(memo[n] != 0){
		return memo[n];
	}
	
	memo[n] = fib(n-1) + fib(n-2);
	return memo[n];
}
