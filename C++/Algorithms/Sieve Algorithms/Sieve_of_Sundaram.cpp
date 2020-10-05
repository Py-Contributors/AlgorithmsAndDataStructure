/*
    Algorithm: Sieve of Sundaram. 
    Given a number n, print all prime numbers less than n
*/

#include <bits/stdc++.h> 
using namespace std; 
  
int sieve_of_sundaram(int n) 
{ 
    // Sieve of Sundaram produces primes smaller than (2*x + 2) for a number given number x. 
    int m = (n-1)/2; 
  
    // This array is used to identify prime number
    vector<bool> visited(m + 1, false);

    //Core : Mark all numbers of the form i + j + 2ij as true where 1 <= i <= j 
    for (int i=1; i<=m; i++) 
        for (int j=i; (i + j + 2*i*j) <= m; j++) 
            visited[i + j + 2*i*j] = true; 
  
    // Since 2 is a prime number, and we will be printing using 2*i + 1 , so 2 will be skipped in this case.
    if (n > 2) cout << 2 << " "; 
    
    // Printing Primes
    for (int i=1; i<=m; i++)
        if (!visited[i])
            cout << 2*i + 1 << " "; 
} 
  
int main(void) 
{ 
    sieve_of_sundaram(50); 
    return 0; 
} 