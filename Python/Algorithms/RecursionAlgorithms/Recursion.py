"""
__FileCreationDate__  : 4/5/2020
__Author__           :  CodePerfectPlus
__Package__         :  Python 3
__GitHub__         : https://www.github.com/codeperfectplus
"""


def recusiveSum(number):
    # Base Case
    if number == 1:
        return 1
    else:
        return number + recusiveSum(number - 1)


print(recusiveSum(5))
