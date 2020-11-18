/*
Title - Longest Increasing Subsequence.

Given an array it will find the length of the longest subsequence in that array
which is strictly increasing. 
This algo can be modified to stor that same subsequence.

This algorithm uses Dynamic Programming to find the LIS.

Complexity - O(n*n)
*/
#include<bits/stdc++.h>
using namespace std;

/*
Below lis function calculate the LIS for given input array as parameter.

This uses a bottom up approach for finding LIS ending at each element.

Algorithm:
1. Initialize an array of length n, which stores the length of max LIS possible till a given index i (incusive).
2. For each index, minimum possible LIS is 1 (formed bhy it's own element)
3. For each index, check for all elemnts smaller than current and present on left side. Max LIS is possible by inclusion of any of these.
*/

int lis( int arr[], int n )  
{  
    // dp array, here max increasing subsequence, possible till a given index, inclusive of that index.
    int dp[n]={0}; 
  .
      
  
    /* Compute optimized LIS values in  
       bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
       //using binary search for O(NLOGN) code
        int l=upper_bound(dp,dp+n+1,arr[i])-dp;
        if(dp[l-1]<arr[i] and a[i] <dp[l])
            dp[l]=arr[i];
    } 
  
    // Return maximum value in dp[] array. 
    return *max_element(dp, dp+n); 
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /*
        The above code is for taking input form command line.
        n= length of array
        then inputs n elements, the members of array.

        If directly want run, without inputs and with sample example. Comment line 50 to 56.
        Uncomment line 65 and 66.
    */

    // n = 9;
    // int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80}; 
    cout<<"The length of Longest Increasing Subsequence is = "<<lis(arr,n)<<endl;
    
}
/*  Sample Input array = {10, 22, 9, 33, 21, 50, 41, 60, 80}

Output = 6.
The LIS here is formed by {10,22,33,50,60,80}
*/
