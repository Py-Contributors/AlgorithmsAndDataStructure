# Sieve of Eratosthenes
# It is an efficient algorithm used to find all the prime numbers smaller than
# or equal to a number(n)
# We will create a list and add all the elements and then remove those elements
#  which are not prime


def sieveOfEratosthenes(n):
    # Creating an empty list
    primeList = []

    for i in range(2, n + 1):
        # Adding all the elements
        primeList.append(i)

    i = 2
    while i * i <= n:
        if i in primeList:
            # Here we will remove all the elements that are multiples of i less
            # than n + 1 and greater than i
            for j in range(i * 2, n + 1, i):
                if j in primeList:
                    primeList.remove(j)

        i = i + 1

    print(primeList)


n = int(input("Enter the number upto which \
        you want to print the prime numbers :"))
sieveOfEratosthenes(n)
