"""
__FileCreationDate__  :  4/5/2020
__Author__           :  CodePerfectPlus
__Package__         :  Python 3
__GitHub__         : https://www.github.com/codeperfectplus
"""


def factorial(n):
    # Base Case
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)


# print(factorial(5))
