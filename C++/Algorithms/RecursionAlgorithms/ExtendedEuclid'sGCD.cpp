/*Extended Euclid's GCD

An algorithm to compute integers x and y such that
ax + by = gcd(a,b) for given a and b.
*/

#include <iostream>
using namespace std;
int gcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main()
{
    int x = 0, y = 0, a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << ": ";
    cout << gcd(a, b, x, y);
    return 0;
}