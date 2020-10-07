# Turning into 1's complement
def complement1s(lis_32b):
    for j in range(0, 32):
        if lis_32b[j] == 0:
            lis_32b[j] = 1
        else:
            lis_32b[j] = 0
    return lis_32b

# Turning 1's complement into 2's complement


def complement2s(lis_32b):
    if lis_32b[31] == 0:
        lis_32b[31] = 1
    else:
        i = 31
        while lis_32b[i] != 0:
            lis_32b[i] = 0
            i -= 1
        lis_32b[i] = 1
    return lis_32b
