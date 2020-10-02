#include <iostream>
using namespace std;

// Recursive function to return Fibonacci List
int fibonacciList(int n)
{
    // Checks if n<=1, i.e. 0 and 1
    if (n <= 1)
    {
        return n;
    }
    else
    {
        // Returns the function recursively for the next number
        return fibonacciList(n - 1) + fibonacciList(n - 2);
    }
}

int main()
{

    /* 
        Fibonacci List Algorithm Implementation in C++
        
        Output : Return the the first 'n' elements of the Fibonacci Series 
        Time complexity : O(n*2^n)

        Example:
        n=10

        Output:
        0 1 1 2 3 5 8 13 21 34
    */

    int n, m1 = 0, m2 = 1;
    n = 10;
    for (int i = 0; i < n; i++)
        cout << fibonacciList(i) << " ";
    cout << endl;
}