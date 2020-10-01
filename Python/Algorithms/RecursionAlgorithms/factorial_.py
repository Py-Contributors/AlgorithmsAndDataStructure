"""
Factorial of a number
Title - Calculate the factorial of a number
GitHub: https://www.github.com/lucastrogo
"""


def fat(num):
    """Calculate the factorial of a number"""
    ret = 1
    for elem in range(1, num + 1):
        ret *= elem

    return ret


print(fat(5))
