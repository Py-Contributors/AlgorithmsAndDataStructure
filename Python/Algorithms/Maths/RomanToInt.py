# !/usr/bin/env python3.6
'''
Converts Roman Numeral into Decimal Number'''

mapping = (
    ('M', 1000),
    ('CM', 900),
    ('D', 500),
    ('CD', 400),
    ('C', 100),
    ('XC', 90),
    ('L', 50),
    ('XL', 40),
    ('X', 10),
    ('IX', 9),
    ('V', 5),
    ('IV', 4),
    ('I', 1),)


def romanToInt(s):
    ans = index = 0
    for (numeral, number) in mapping:
        while s[index:index + len(numeral)] == numeral:
            ans += number
            index += len(numeral)
    return ans


print(romanToInt('IX'))  # 9
print(romanToInt('X'))  # 10
print(romanToInt('LVIII'))  # 58


# Integer to Roman


import math
  
def integerToRoman(A):
    romansDict = \
        {
            1: "I",
            5: "V",
            10: "X",
            50: "L",
            100: "C",
            500: "D",
            1000: "M",
            5000: "G",
            10000: "H"
        }
  
    div = 1
    while A >= div:
        div *= 10
  
    div /= 10
  
    res = ""
  
    while A:
  
        lastNum = int(A / div)
  
        if lastNum <= 3:
            res += (romansDict[div] * lastNum)
        elif lastNum == 4:
            res += (romansDict[div] +
                        romansDict[div * 5])
        elif 5 <= lastNum <= 8:
            res += (romansDict[div * 5] +
            (romansDict[div] * (lastNum - 5)))
        elif lastNum == 9:
            res += (romansDict[div] +
                        romansDict[div * 10])
  
        A = math.floor(A % div)
        div /= 10
          
    return res

print("Roman value for the integer is:"
                + str(integerToRoman(3549)))