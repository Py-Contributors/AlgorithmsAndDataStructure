# Description :- 
# Unbounded knapsack is similar to 0/1 knapsack but here we assume we can take 1 item many times
# In 0/1 knapsack we add 1 item and then dont consider it again or you can say we have single piece of that item
# But in Unbounded Knapsack we take multiple pieces of a item so we can add it as many times we want till sack is not full
# repitition of items is allowed

# Contributed by :- Tejas Bir Singh

def unboundedKnapsack(weightArray, ProfitArray, KnapsackCapacity, N):

	dp =[[-1] * (KnapsackCapacity+1)] * (N+1)  # intialize 2D matrix ,it will be having N+1 rows and Capacity+1 columns
	# we take +1 here because we need to make base conditions i.e 0 capacity or 0 items
	# if we have 0 capacity than our max profit will be as 0 because we can't add any item in sack if we dont; have a sack only 
	# other case is if we don't have items then also our profit will be 0 because we can't take anything
	
	# initializing the base conditions as mentioned above
	for i in range(0,KnapsackCapacity+1):
		dp[0][i]=0
	for i in range(0,N+1):
		dp[i][0]=0

	# we will have to use 2 nested loops to traverse over whole array starting from 1st row and column
	# as we ahve already initialized first row and column as base conditions
	for i in range(1,N+1):
		for j in range(1,KnapsackCapacity+1):
			# if our capacity of sack is more than the weight of the item then we will add it

			if(weightArray[i-1] < j):
				# we will find the max of the current profit that we can get adding current item 
				# and previous profit in upper row same column

				dp[i][j] = max(ProfitArray[i-1]+dp[i][j-weightArray[i-1]],dp[i-1][j])
				# if we don't have capacity to add current item then we will set profit to previous profit
			else:
				dp[i][j] = dp[i-1][j]

	# for i in dp:
	# 	print(i)
	# we will return the last block of our matrix as it will contain the max profit that we can get 

	return dp[N][KnapsackCapacity]


# Driver Code
if __name__ == '__main__':
	weightArray =[5,10,8,5]  # weight of the items that we will add
	ProfitArray = [40,30,50,25]   #profit for all the items that we can add
	N = len(weightArray)
	KnapsackCapacity = 120 #max capacity of our sack 
	print(unboundedKnapsack(weightArray, ProfitArray, KnapsackCapacity, N))