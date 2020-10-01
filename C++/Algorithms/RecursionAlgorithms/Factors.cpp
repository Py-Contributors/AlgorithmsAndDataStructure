#include <iostream>
using namespace std;

void factors(int n, int i)
{
    // Checking if the number is less than n
    if (i <= n)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
        // Calling the function recursively for the next number
        factors(n, i + 1);
    }
}

int main()
{
    /* 
        Factors Algorithm Implementation in C++
        
        Output : Return the factors of number 'N'
        Time complexity : O(n)

        Example:
        N=16

        Output:
        1 2 4 8 16
    */

    int N = 16;
    factors(N, 1);
    cout << endl;
}