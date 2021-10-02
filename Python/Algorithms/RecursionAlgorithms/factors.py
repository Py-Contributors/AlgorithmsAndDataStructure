"""
__FileCreationDate__  :  2/10/2021
__Author__           :  thearkamitra
__Package__         :  Python 3
__GitHub__         : https://www.github.com/thearkamitra
"""


def factors(n, i):
    ## Using sqrt(n) reduces complexity from O(n) to O(sqrt(n))
    if i*i <= n: 
        if n % i == 0:
            print(i, end="|")
            if i*i!=n:
                print(n//i, end="|")
        factors(n, i + 1)


if __name__ == "__main__":
    factors(10, 1)
