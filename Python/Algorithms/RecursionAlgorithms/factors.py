"""
__FileCreationDate__  :  4/5/2020
__Author__           :  CodePerfectPlus
__Package__         :  Python 3
__GitHub__         : https://www.github.com/codeperfectplus
"""


def factors(n, i):
    if i <= n:
        if n % i == 0:
            print(i, end="|")
        factors(n, i + 1)


if __name__ == "__main__":
    factors(10, 1)
