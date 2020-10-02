"""
Insertion Sort
Array or list will be sorted using this technique
Sorted Array at each will be shown
"""
a=[4,8,9,5,1]

#selectionsort 

listLength=len(a)
print("initial array-",a)
print("------------------------")   

for i in range(listLength):
    minindex = i
    for j in range(i+1,listLength):
        if a[minindex] > a[j]:
            minindex = j
    a[i],a[minindex] = a[minindex],a[i]

    #This will show the sorted array at each step
    print("Sorted array at step", i+1, a)        

print("------------------------")
print("Final sorted array is:",a)
