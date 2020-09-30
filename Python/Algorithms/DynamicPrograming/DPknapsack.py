def knapSack(capacity, wt, val, n): 
	K = [[0 for x in range(capacity + 1)] for x in range(n + 1)] 
	for i in range(n + 1): 
		for w in range(capacity + 1): 
			if i == 0 or w == 0: 
				K[i][w] = 0
			elif wt[i-1] <= w: 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]) 
			else: 
				K[i][w] = K[i-1][w] 

	return K[n][capacity] 

value = [50, 90, 120, 30] 
weight = [5, 10, 9, 4] 
capacity = 20
n = len(value) 
print(knapSack(capacity, weight, value, n)) 
