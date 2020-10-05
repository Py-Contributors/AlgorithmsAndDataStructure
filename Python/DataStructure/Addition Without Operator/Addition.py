# Title : Python3 Program to add two numbers without using arithmetic operator


def Add(a, b):

    # Iterate till there is no carry
    while b != 0:

        # carry now contains common set bits of x and y
        carry = a & b

        # Sum of bits of x and y where at least one of the bits is not set
        a = a ^ b

        # Carry is shifted by one so that adding it to x gives the required sum
        b = carry << 1

    return a


# Declear Print statement and Pass Parameter on them i.e Print(Add(20,10))
print(Add(10, 20))
