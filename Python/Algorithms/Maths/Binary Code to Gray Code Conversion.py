# Author : Utsav Ramchandra Khatu
# Binary Code to Gray Code Conversion
print("Press b if you want to convert Binary code to Grey Code else Press i to convert Integer to Grey Code")
s = input()
while s != 'b' and s != 'i' :
    print("Invalid Response Please Try Again")
    s = input()
if s == 'i' :
    n = int(input("Please enter the integer:"))
    a = []
    while n:
        a.append(n % 2)
        n //= 2
    a = a[::-1]
else :
    x = list(input("Please enter the binary number"))
    a = [int(x[i]) for i in range(len(x))]
gray_code = [0 for i in range(len(a))]
for i in range(len(a)):
    if i == 0:
        gray_code[i] = a[i]
    else:
        gray_code[i] = a[i] ^ a[i - 1]
print("Binary Code : " + "".join(map(str, a)))
print("Gray Code : " + "".join(map(str, gray_code)))
