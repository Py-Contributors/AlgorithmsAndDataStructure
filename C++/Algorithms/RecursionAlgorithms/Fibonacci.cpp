// Title - Fibonacci Series Using Recursion
// It will print the fibonacci series upto n terms

#include <iostream>
using namespace std;
int fib(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fib(x-1)+fib(x-2));
   }
}
int main() {
   int x , i=0;
   cout << "Enter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series : ";
   while(i < x) {
      cout << " " << fib(i);
      i++;
   }
   return 0;
}

/*  TEST CASES

Test Case - 1

Enter the number of terms of series : 10

Fibonnaci Series :  0 1 1 2 3 5 8 13 21 34

Test Case - 2

Enter the number of terms of series : 30

Fibonnaci Series :  0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229

*/
