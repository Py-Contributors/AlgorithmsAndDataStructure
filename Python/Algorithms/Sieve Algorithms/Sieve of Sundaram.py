"""
    Sieve of Sundaram :
    Given a number n, print all primes smaller than or equal to n.
"""


def sieve_of_sundaram(n):
    n_cap = int((n - 1) / 2)
    marked = [0] * (n_cap + 1)

    for i in range(1, n_cap + 1):
        j = i
        while((i+j+2*i*j) <= n_cap):
            marked[i+j+2*i*j] = 1
            j += 1
    primes = []

    if (n > 2):
        primes.append(2)

    for i in range(1, n_cap + 1):
        if (marked[i] == 0):
            primes.append(2*i+1)

    return primes


print(sieve_of_sundaram(25))
