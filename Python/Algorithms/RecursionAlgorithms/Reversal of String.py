def rs(st,n):
    if n>0:
        print(st[n],end='')
        rs(st,n-1)
    elif n==0:
        print(st[0])



s=str(input('Enter a String'))
rs(s,len(s)-1)

