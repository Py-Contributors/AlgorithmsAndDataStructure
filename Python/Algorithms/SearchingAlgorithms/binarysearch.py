from bisect import bisect_left,bisect

def binsearchright(a,k):
    c = bisect(a, k)
    return c

def binsearchleft(a,k):
    b = bisect_left(a,k)
    return b
a  = [1,1,2,2,2,4,4,4,4,4,4,8,8] 
k = int(8) 
res = binsearchleft(a, k)
res1 = binsearchright(a,k)  
print("{} is present {} times in the array".format(k,abs(res-res1))) 