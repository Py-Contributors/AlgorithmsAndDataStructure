'''
Converts Roman Numeral into Decimal Number'''

mapping = (('M',  1000),
              ('CM', 900),
              ('D',  500),
              ('CD', 400),
              ('C',  100),
              ('XC', 90),
              ('L',  50),
              ('XL', 40),
              ('X',  10),
              ('IX', 9),
              ('V',  5),
              ('IV', 4),
              ('I',  1))
def romanToInt(s):
    ans = index = 0
    for numeral,number in mapping:
        while s[index:index+len(numeral)] == numeral:
            ans += number
            index += len(numeral)
    return ans


print(romanToInt("IX")) #9
print(romanToInt("X")) #10
print(romanToInt("LVIII")) #58
