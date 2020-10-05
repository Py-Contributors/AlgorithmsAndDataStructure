// Title - Longest Palindromic Subsequence
// Statement - It will find the length of the Longest Palindromic Subsequence in a string
// Time complexity - O(n^2)

#include<bits/stdc++.h> 
using namespace std;
  
// Returns the length of the longest palindromic subsequence in given string
int lps(string &str) 
{ 
   int n = str.length(); 
   int i, j, cl; 
   int L[n][n];  // Table to store results of subproblems 
  
  
   // Strings of length 1 are palindrome of length 1 
    for (i = 0; i < n; i++) 
        L[i][i] = 1; 
    
    // Iterate through substrings of length 2 to n
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
} 
  
int main() 
{ 
    string str;
    cin>>str;
    if (str.length()==0) cout<<0; 
    else printf ("The length of the LPS is %d", lps(str)); 
    return 0; 
} 