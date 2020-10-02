""" Sum of Digits Algorithm Implementation in Python 3
Code generates a random 3 digit integer and finds the sum of its digits
time complexity : O(log N)
"""
from random import randint

sum = 0
a = randint(100, 999)
print(a)
while a / 10 != 0:
    sum = sum + a % 10
    a = a // 10

print(sum)
