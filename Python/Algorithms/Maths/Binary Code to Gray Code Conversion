# Author : Utsav Ramchandra Khatu
# Binary Code to Gray Code Conversion

n = int(input())
a = []
while n :
    a.append(n%2)
    n //= 2
a = a[::-1]
gray_code = [0 for i in range(len(a))]
print(a)
for i in range(len(a)) :
    if i == 0 :
        gray_code[i] = a[i]
    else :
        gray_code[i] = a[i]^a[i-1]
print("Binary Code : " + "".join(map(str,a)) )
print("Gray Code : " + "".join(map(str,gray_code)))
