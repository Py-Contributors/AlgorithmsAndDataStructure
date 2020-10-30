from collections import OrderedDict 

n=int(input())
w= OrderedDict()
for i in range(0,n) :
   m=(input())
   if m in w :
        w[m]+=1
   else :
        w[m]=1

print(len(w))
for _ in w :
    print(w[_], end=" ")
