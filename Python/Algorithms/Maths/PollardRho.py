"""
Title - Pollard's Rho Algorithm
Purpose - Performs factorization on a number.
Time Complexity - O(√n)
"""
import random
import math


class PollardRho:
    """ Pollard's Rho Algorithm Implementation

        n: an non negative integer
        output: factorization of n
        Example: 54 -> 3, 2

    """

    def __init__(self):
        print("Pollard's Rho Algorithm Initialized.")

    def _mod_step(self, x, n):
        return (x ** 2 + 1) % n

    def __call__(self, n):
        x = 2
        y = 2
        d = 1
        try:
            f = self._mod_step
            while d == 1:
                x = f(x, n)
                y = f(f(y, n), n)
                d = math.gcd(abs(x - y), n)
            return d
        except TypeError:
            return False


rho = PollardRho()
rand1 = random.randint(1, 100)
factors = [1]
f = rho(rand1)
max_tries = 200
counter = 0
while f != rand1 and counter <= max_tries:
    f = rho(f)
    if f not in factors:
        factors.append(f)
    f = rand1 // f
    counter += 1
factors += [rand1]
factors = map(str, factors)  # convert to str for .join
print(f'Factors of {rand1} include {", ".join(factors)}.')
