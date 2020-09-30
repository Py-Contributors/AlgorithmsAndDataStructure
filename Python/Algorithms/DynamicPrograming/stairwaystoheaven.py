known = {}
def stariways(n):
    if n in known:
        return known[n]
    if n==1:
        value = 1
    elif n==2:
        value = 2
    elif n>2:
        value = stariways(n-1)+stariways(n-2)
    known[n] = value
    return value
print(stariways(3))