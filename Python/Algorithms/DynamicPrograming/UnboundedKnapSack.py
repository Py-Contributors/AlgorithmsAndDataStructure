"""	Unbounded Knapsack Implementation in Python 3+

		Weight arr: consists of the items weights 
		Profit arr: consists of the profit of items
		Capacity:  Capacity of Sack
		Time Complexity:- O(Capacity * number of items) = O(N^2)
		Space Comlexity:- O(Capacity * number of items) = O(N^2)

		Example: 
		>>> knapsack = UnboundedKnapsack()
		>>> knapsack([5,10,8,5] ,[40,30,50,25],120)
		930
"""

class UnboundedKnapsack:
	
	def __init__(self):
		print("Unbounded Knap Sack algorithm is initialized")

	def __call__(self,weightArray, ProfitArray, KnapsackCapacity, N):

		dp =[[-1] * (KnapsackCapacity+1)] * (N+1) 		
		# Initialize the first column with 0
		for i in range(0,KnapsackCapacity+1):
			dp[0][i]=0
		# Initialize the first row with 0
		for i in range(0,N+1):
			dp[i][0]=0

		for i in range(1,N+1):
			for j in range(1,KnapsackCapacity+1):	
				# If weight of item is less than available capacity of sack 
				if(weightArray[i-1] < j):			
					dp[i][j] = max(ProfitArray[i-1]+dp[i][j-weightArray[i-1]],dp[i-1][j])
				# If weight of item is more than available capacity
				else:
					dp[i][j] = dp[i-1][j]

		return dp[N][KnapsackCapacity]


knapsack = UnboundedKnapsack()
print(knapsack([5,10,8,5] , [40,30,50,25] , 120 , 4))
