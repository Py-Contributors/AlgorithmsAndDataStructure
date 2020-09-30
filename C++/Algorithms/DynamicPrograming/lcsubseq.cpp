/* Implementation of C++ code of LCS problem */
#include<iostream> 
using namespace std; 
  
int max(int a, int b);  
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcseq( char *X, char *Y, int m, int n )  
{  
    if (m == 0 || n == 0)  
        return 0;  
    if (X[m-1] == Y[n-1])  
        return 1 + lcseq(X, Y, m-1, n-1);  
    else
        return max(lcseq(X, Y, m, n-1), lcseq(X, Y, m-1, n));  
}  
  
/* Utility function to get max of 2 integers */
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Driver code */
int main()  
{  
    char x[10000];  
    char y[10000]; 
    int m, n; 
      
    cout<<"Enter first string:\n";
    cin>>x;
    cout<<"Enter second string:\n";
    cin>>y;
    //Finding length of string
    int count1 = 0;
    for(int i = 0; x[i] != '\0'; i++){
       count1++;
    }
    int count2 = 0;
    for(int i = 0; y[i] != '\0'; i++){
       count2++;
    }

    m = count1;
    n = count2;
    cout<<"Length of LCS is "<< lcseq( x, y, m, n ) ;  
      
    return 0;  
}  
  
// This code is contributed by Akhil
