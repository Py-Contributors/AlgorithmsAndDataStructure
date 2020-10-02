"""
    Sieve of Sundaram :
    Given a number n, print all primes smaller than or equal to n.
"""


def sieve_of_sundaram(n):

    # For primes less than n, reduce n to half
    n_cap = int((n - 1) / 2)
    # Initially all elements are unmarked
    marked = [0] * (n_cap + 1)

    # Numbers of the form i + j + 2ij are marked
    # if 1 <= i <= j
    for i in range(1, n_cap + 1):
        j = i
        while((i + j + 2 * i * j) <= n_cap):
            marked[i + j + 2 * i * j] = 1
            j += 1
    primes = []
    # Since 2 is a prime number
    if (n > 2):
        primes.append(2)

    # Print the remaining unmaked numbers
    # of the form 2 * i + 1
    for i in range(1, n_cap + 1):
        if (marked[i] == 0):
            primes.append(2 * i + 1)

    return primes


print(sieve_of_sundaram(25))
