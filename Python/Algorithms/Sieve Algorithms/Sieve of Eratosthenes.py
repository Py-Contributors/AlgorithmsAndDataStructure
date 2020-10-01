"""
    Sieve of Eratosthenes :

    Generate all the primes less than any integer nn
"""
from math import sqrt


def get_primes(n):
    m = n + 1
    # numbers = [True for i in range(m)]
    numbers = [True] * m
    for i in range(2, int(sqrt(n) + 1)):
        if numbers[i]:
            for j in range(i * i, m, i):
                numbers[j] = False
    primes = []
    for i in range(2, m):
        if numbers[i]:
            primes.append(i)
    return primes


print(get_primes(25))
