
"""
This will give the answer of the unsigned right sift operator.
First yinput is given then the input is:
converted to 32-bit binary
It's 1's complement
It's 2's complement
MSb shift
Adding the sum and giving the output.

"""
import binary
import complement
import msbshift
# Taking the input for the unsigned right sift operator
left_operand = int(input("Input the left operand "))
right_operand = int(input("Input the right operand "))
# convert decimal to 32 bit binary
lis_32b = binary.convert(left_operand)
# Turning into i's complement
comp1s = complement.complement1s(lis_32b)
# Turning into 2's complement
comp2s = complement.complement2s(comp1s)
# msb shifting and putting zero
msb_l = msbshift.shift(right_operand, comp2s)
# sum
iterate = 31
a = 1
sum = 0
while iterate >= 0:
    sum = sum + a * msb_l[iterate]
    b = a
    a += b
    iterate -= 1
print(left_operand, ">>>", right_operand, ":", sum)
