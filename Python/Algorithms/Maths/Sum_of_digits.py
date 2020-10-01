#Python Program to Compute Sum of Digits of a Number
#Issue 114

def compute(n):
    sum = 0
    while (n / 10 != 0):
        sum = sum + n % 10
        n = n // 10
    return sum
    
a = 389     #can be any 3 digit number
compute(a)
