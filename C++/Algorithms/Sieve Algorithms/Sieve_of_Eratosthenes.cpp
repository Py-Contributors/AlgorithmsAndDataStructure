/*
    Sieve of Eratosthenes:
    Given a number n, print all prime numbers less than n
*/

#include <iostream>
using namespace std;

void sieve_of_eratosthenes(int n)
{
    /*
    This will print all 
    prime number less than n
    */

    // Initially all are prime
    bool *prime = new bool[n];
    for (int i = 0; i < n; i++)
    {
        prime[i] = true;
    }

    // Now we start marking multiples of every number non-prime
    for (int i = 2; i * i <= n; i++)
    {
        // We start from first multiple and go till n
        for (int j = 2 * i; j < n; j += i)
        {
            prime[j] = false;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    sieve_of_eratosthenes(50);
}
