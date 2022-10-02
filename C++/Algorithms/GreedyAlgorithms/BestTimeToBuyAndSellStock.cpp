You are given array prices [] which contain the price of a stock on some days. You have to choose one day for buying the stock and a different one for selling it. Return the days on which you buy and sell the stock.
  //author - Sushrut Shukla
  
#include
#include<bits/stdc++.h>

using namespace std;

int main() {
    //Implementing the array for prices on ith days of stock
    int n = 6;
    vector<int> prices = {7,1,5,3,6,4};
    
    //for storing best days to buy and sell stock
    pair<int,int> ans;
    //For storing maximum profit
    int maxProfit = 0;
    //For storing minimum purchase of stock
    int minBuy = INT_MAX;
    //index of minbuy
    int ind;
    
    for(int i=0;i<prices.size();i++){
        
        //if we get min price for buying than earlier then we update minBuy and its index
        if(minBuy>prices[i]){
            ind = i;
            minBuy = prices[i];
        }
        
        //Finding maximum profit by checking selling at ith day prices with minBuy
        if(maxProfit<prices[i] - minBuy){
            maxProfit=prices[i] - minBuy;
            ans = {ind,i};      // storing the days of buying and selling
        }
    }
    
    //Printing the best time to buy and sell stock and its maximum profit
    cout<<"Best Time to buy on day "<<ans.first+1<<" and sell on day "<<ans.second+1<<endl;
    cout<<"Maximum Profit Will be "<<maxProfit;
    return 0;
}

Output -
Best Time to buy on day 2 and sell on day 5.
Maximum Profit Will be 5
