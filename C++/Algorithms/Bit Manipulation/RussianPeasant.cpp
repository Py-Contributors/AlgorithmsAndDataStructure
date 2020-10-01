/*Russian Reasant Algorithm

In this algorithm, two numbers are multiplied without using multiplication operator.
We double the first number and halve the second number repeatedly till the second number doesn’t become 1. 
In the process, whenever the second number becomes odd, we add the first number to result.
*/

#include <iostream>
using namespace std;
int main()
{
    int a, b, result = 0;

    cout << "Enter two numbers to multiply: \n";
    cin >> a >> b;
    while (b > 0)
    {
        if (b % 2 != 0)
        {
            result += a;
        }
        a = a << 1;
        b = b >> 1;
    }
    cout << "Product: " << result;
    return 0;
}