#include <iostream>
using namespace std;

int fibonacciNumber(int n){
    // Checks if n<=1, i.e. 0 and 1
    if(n<=1) {
        return n;
    }
    else {
        // Returns the function recursively for the next number 
        return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
    }
}

int main() {
    
    /* 
        Fibonacci Numbers Algorithm Implementation in C++
        
        Output : Return the element at the index 'i' in a Fibonacci series.
        Time complexity : O(n)

        Example:
        i=3

        Output:
        2
    */

    int i=3;
    cout << fibonacciNumber(i)<<endl;
}