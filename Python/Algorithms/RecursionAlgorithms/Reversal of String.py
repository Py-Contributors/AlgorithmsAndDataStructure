'''

Title- Reversal of string
it will reverse any of type Character that you will provide

'''
#recursive function that reverses the string
def rs(st,n):
    if n>0:
        print(st[n],end='')
        rs(st,n-1)
    elif n==0:
        print(st[0])


#__main__
s=str(input('Enter a String'))
rs(s,len(s)-1)

