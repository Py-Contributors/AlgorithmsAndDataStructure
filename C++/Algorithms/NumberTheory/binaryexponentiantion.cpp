#include <iostream>
using namespace std;
#define M 1000000007
//Binary exponentiation
//Calculating a^n in O(log n) time complexity

// int power(int a,int n)
// {
//     int res=1;
//     while(n>0)
//     {
//         if(n&1)   //if n is odd
//         {
//             res = res*a;
//         }
//         a = a*a;      // Using property a^n = (a^2)^(n/2)
//         n = n/2;
//     }
//     return res;
// }
int power(int x,int y)
{
    int res=1;
    
    while(y>0)
    {
       if(y&1)
       res=((res%M)*(x%M))%M;
       
       y=y>>1;
       x=((x%M)*(x%M))%M;
    }
    re res;
} 

int main()
{
    cout<<power(8,4)<<"\n";
    cout<<power(10,5)<<"\n";
}
