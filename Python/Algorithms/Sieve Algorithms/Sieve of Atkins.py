# Python 3 program for 
# implementation of 
# Sieve of Atkin 

def SieveOfAtkin(limit): 

	# 2 and 3 are known 
	# to be prime 
	if (limit > 2): 
		print(2 , end = " ") 
	if (limit > 3): 
		print(3 , end = " ") 

	# Initialise the sieve 
	# array with False values 
	sieve = [False] * limit 
	for i in range( 0 , limit ): 
		sieve[i] = False
		
	'''Mark siev[n] is True if 
	one of the following is True: 
	a) n = (4*x*x)+(y*y) has odd 
	number of solutions, i.e., 
	there exist odd number of 
	distinct pairs (x, y) that 
	satisfy the equation and 
	n % 12 = 1 or n % 12 = 5. 
	b) n = (3*x*x)+(y*y) has 
	odd number of solutions 
	and n % 12 = 7 
	c) n = (3*x*x)-(y*y) has 
	odd number of solutions, 
	x > y and n % 12 = 11 '''
	x = 1
	while(x * x < limit ) : 
		y = 1
		while(y * y < limit ) : 
			
			# Main part of 
			# Sieve of Atkin 
			n = (4 * x * x) + (y * y) 
			if (n <= limit and (n % 12 == 1 or
								n % 12 == 5)): 
				sieve[n] ^= True

			n = (3 * x * x) + (y * y) 
			if (n <= limit and n % 12 == 7): 
				sieve[n] ^= True

			n = (3 * x * x) - (y * y) 
			if (x > y and n <= limit and
						n % 12 == 11): 
				sieve[n] ^= True
			y += 1
		x += 1
	
	# Mark all multiples of 
	# squares as non-prime 
	r = 5
	while(r * r < limit) : 
		if (sieve[r]) : 
			for i in range(r * r, limit, r * r): 
				sieve[i] = False
		
	# Print primes 
	# using sieve[] 
	for a in range(5 , limit ): 
		if (sieve[a]): 
			print(a , end = " ") 

# Driver Code 
limit = 20
SieveOfAtkin(limit) 

# This code is contributed 
# by Smitha 
