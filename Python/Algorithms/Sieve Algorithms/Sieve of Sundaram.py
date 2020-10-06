"""
    Sieve of Sundaram :
    Given a number n, print all primes smaller than or equal to n.
"""


def sieve_of_sundaram(n):
    # For primes smaller than n reduce n to half
    n_cap = int((n - 1) / 2)
    # Make all elements unmarked
    marked = [0] * (n_cap + 1)

    # Mark all numbers of the form i + j + 2ij
    for i in range(1, n_cap + 1):
        j = i
        while((i + j + 2 * i * j) <= n_cap):
            marked[i + j + 2 * i * j] = 1
            j += 1
    primes = []

    # 2 is a prime
    if (n > 2):
        primes.append(2)

    # Numbers of the form 2 * i + 1 are prime
    for i in range(1, n_cap + 1):
        if (marked[i] == 0):
            primes.append(2 * i + 1)

    return primes


num = int(input("Please enter the number: "))
# print(sieve_of_sundaram(25))
print(sieve_of_sundaram(num))
