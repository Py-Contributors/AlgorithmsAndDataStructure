/* 
Title - Recusive Factorial
Description- A Program to recursively calculate factorial of a positive integer.
Note- This allows to calculate factorials of numbers upto 20. After 20, the factorial 
value will exceed the capacity of largest positive integer data type [unsigned long long].
*/

#include<bits/stdc++.h>

using namespace std;

// A recursive function to calculate the factorial a positive integer.
unsigned long long recursiveFactorial(unsigned int num)
{
    if(num<=1)
        return 1;
    return num * recursiveFactorial(num-1);
}

int main()   
{
    int num;
    cout << "\n Enter a positive integer to find its factorial: ";
    cin >> num;
    if(num < 0){
        cerr << "\n Cannot compute factorial of a negative number.\n";
        return 1;
    }
    if(num > 20){
        cerr << "\n Factorial of "<< num << " exceeds the limit of c++ integers.\n";
        return 1;
    }
    
    cout << "\n Factorial of " << num << " is = " << recursiveFactorial(num) << "\n"; 
    return 0;
}

/*
Time complexity -   O(n)
Space complexity -  O(n) ( Because maximum functions in the stack = N )

SAMPLE OUTPUT 1:

 Enter a positive integer to find its factorial: 10

 Factorial of 10 is = 3628800


SAMPLE OUTPUT 2:

 Enter a positive integer to find its factorial: 20 

 Factorial of 20 is = 2432902008176640000


SAMPLE OUTPUT 3:

 Enter a positive integer to find its factorial: 21

 Factorial of 21 exceeds the limit of c++ integers.
*/
