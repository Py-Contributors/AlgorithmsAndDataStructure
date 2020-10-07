# msb shifting and putting zero in place
def shift(right_operand, comp2s):
    i = 0
    msb_l = list()
    while i < right_operand:
        msb_l.append(0)
        i += 1
    comp2s = comp2s[0: 32 - right_operand]
    for bit in comp2s:
        msb_l.append(bit)
    return msb_l
