// Program to recursively calculate sum of numbers from 1 to n

#include<iostream>
using namespace std;

// function to recursively calculate sum of numbers from 1 to n
int recurSum(int n)
{
    if(n == 0) return 0;   // base case
    return (recurSum(n - 1) + n);   // recursive case
}
int main()   
{
    int n;
    cout<<"\nEnter N to find sum from 1 to N = ";
    cin>>n;     // taking input

    cout<<"\nSum from 1 to "<< n <<" = "<<recurSum(n);    // final output

    return 0;
}
