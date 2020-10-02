#include <iostream>
using namespace std;

//Binary exponentiation
//Calculating a^n in O(log n) time complexity

int power(int a,int n)
{
    int res=1;
    while(n>0)
    {
        if(n&1)   //if n is odd
        {
            res = res*a;
        }
        a = a*a;      // Using property a^n = (a^2)^(n/2)
        n = n/2;
    }
    return res;
}

int main()
{
    cout<<power(8,4)<<"\n";
    cout<<power(10,5)<<"\n";
}
