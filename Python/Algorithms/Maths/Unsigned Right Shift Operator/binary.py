def convert(left_operand):
    # turns left operand into binary
    lo_byte = list(bin(left_operand))
    # strips the 0b part from the binary
    lo_byte = lo_byte[2:]
    lis_32b = list()
    i = 0
    # Appending zero to make 32-bit
    while i <= 31-len(lo_byte):
        lis_32b.append(0)
        i += 1
    for num in lo_byte:
        lis_32b.append(int(num))
    return lis_32b
