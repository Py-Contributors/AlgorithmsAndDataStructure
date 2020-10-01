# Algorithms

- [Algorithms](#algorithms)
  - [Sieve of Eratosthenes](#sieve-of-eratosthenes)

## Sieve of Eratosthenes

Sieve of Eratosthenes is a simple and ancient algorithm used to find the prime numbers up to any given limit. It is one of the most efficient ways to find small prime numbers.

In the following algorithm, the number 0 represents a composite number.

- To find out all primes under nn, generate a list of all integers from 2 to n. (Note: 1 is not prime)
- Start with a smallest prime number, ie p = 2.
- Mark all the multiples of pp which are less than nn as composite. To do this, mark the value of the numbers (multiples of pp) in the generated list as 0. Do not mark pp itself as composite.
- Assign the value of pp to the next prime. The next prime is the next non-zero number in the list which is greater than p.
- Repeat the process until p <= n**1/2