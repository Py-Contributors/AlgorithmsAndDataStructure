/*

Two strings str1 and str2 are given. Find the minimum number of edits required to 
convert ‘str1’ into ‘str2’. There are 3 types of edits: 
1. Insert
2. Remove
3. Replace

*/

#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;  

ll editDistance(string str1, string str2) 
{ 
    ll l1 = str1.length(), l2 = str2.length();
    ll dp[l1 + 1][l2 + 1]; 
  
    for (ll i = 0; i <= l1; i++) { 
        for (ll j = 0; j <= l2; j++) { 
            if (i == 0) 
                dp[i][j] = j;

            else if (j == 0) 
                dp[i][j] = i; 
  
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
  
            else
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
        } 
    } 
    return dp[l1][l2]; 
} 
  

int main() 
{ 
    string str1, str2;
    cin >> str1 >> str2;
    cout << editDistance(str1, str2); 
} 

/*
Explanation:
We are traversing from right ends of both the strings to left.

dp[i][j] -> stores minimum no of operations reqd to convert str1 of length i into str2 of length j.

We are constructing the matrix in a bottom up manner. 
The 4 conditions in the nested loop are for :
1. If str1 is of length 0, then add all j characters of str2
2. If str2 is of length 0, then delete all i characters of str1
3. If last characters of both the strings are same, then ignore them
4. If last characters of both the strings are different, then consider the best of all three possibilities

*/