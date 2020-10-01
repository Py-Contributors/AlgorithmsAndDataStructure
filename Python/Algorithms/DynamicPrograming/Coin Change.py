#Coin Change Problem Solution
#By Abhinav Yadav

class Solution:
    #function to compute the number of combinations that make up that amount 
    def change(self, s: int, l: List[int]) -> int:
        dp=[0]*(s+1) #creating a list of size(s+1) with initial values as '0'
        dp[0]=1
        for i in l:
            for j in range(i,s+1):
                dp[j]+=dp[j-i]   
        return dp[-1] #returning the output
