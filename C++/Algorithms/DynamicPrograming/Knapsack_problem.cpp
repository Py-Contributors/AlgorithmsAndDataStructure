/*

Title - Knapsack Problem solution in C++

Given weights and values of n items, put  these items in a knapsack of capacity W to get the maximum total value in the knapsack.

Remember you can only take an items atmost once. 


INPUT FORMAT
------------
First line will have n and W the number of items, and the maximum weight the knapsack can hold.
Second line will have n integers w1, w2, ... wn where wi is the weight of the i-th item 
Third line will have n integers V1, V2, ... Vn where Vi is the value of the i-th item

OUTPUT FORMAT
-------------
A single integer value which is the maximum value that can be stored in a knapsack

CONSTRAINTS (Set -1)
-----------
0<N<=100
0<W<=10^5
0<wi<=W
0<Vi<=10^9


NOTE:
You cannot divide a item, like take a part of the item, you can either take the whole item or you can't. Since there is just two options we call this 0-1 knapsack. 
*/
#include<bits/stdc++.h>

using namespace std;


int main(){
   long long n, w;
   cin>>n>>w;
   vector<long long> val(n), wt(n);
   for(int i=0; i<n; i++){
    cin>>wt[i];
   }
   for(int i=0; i<n; i++){
    cin>>val[i];
   }

   vector<vector<long long>> dp(n+1, vector<long long>(w+1, 0));
   for(int index=0; index<=n; index++){
    for(int wtSoFar=0; wtSoFar<=w; wtSoFar++){
      if(index==0 || wtSoFar==0){
        dp[index][wtSoFar]=0;
      }else if(wt[index-1]<=wtSoFar){
        dp[index][wtSoFar] = max(dp[index-1][wtSoFar], dp[index-1][wtSoFar-wt[index-1]]+val[index-1]);
      }else{
        dp[index][wtSoFar] = dp[index-1][wtSoFar];
      }
    }
   }

  cout<<dp[n][w]; 
  return 0;  

}

/*
SAMPLE TEST CASE 1:

INPUT
3
8
3 4 5
30 50 60

OUTPUT
90

SAMPLE TEST CASE 2:

INPUT 
6 15
6 5 6 6 3 7
5 6 4 6 5 2

OUTPUT
17

*/



/*

EXPLANATION:

Clearly we can see, we have two choices for every item. Either consider it or don't consider it. So if we consider all the items we will have 2^n choices. 
Now if we use the bruteforce it will exponential, so we will use DP. Our dp array is n*w which is within the memory bounds. Also the runtime is O(n*W) which is quite optimal. 


Dp states: 
1. Index of Item
2. Current Weight. 
DP Value:
Stores the maximum value of items, if we consider 'index' number of items and 'wtSoFar' amount of max weight


let's say we are at the i-th index. We can either take this item. or we can't

CASE 1: We take the item

Then the value will dp[index-1][wtSoFar-wt[index-1]]+val[index-1];
We are doing index-1 becz our weight and value arrays are 1-based indexing

CASE 2: We don't take this item

Then the value will be dp[index-1][wtSoFar]


So, which value to assign. simply MAX(CASE1, CASE2)

*/
