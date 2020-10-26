# counting sort in python by Zahra Shahid

def counting_sort(A,k):    
    length = len(A)                    
    Output = [0] * length               # the sorted output array
    Count = [0] * k                     # the array of count of each number in the given range
    for i in range(0,length):
        Count[A[i]] = Count[A[i]] + 1                

    for i in range(1,k):
        Count[i] = Count[i] + Count[i-1]

    print("The array of count ")
    print(Count)

    j = length -1
    while j >= 0:
        x = A[j]
        Output[Count[x % k]- 1] = A[j]
        Count[x % k] = Count[x % k] - 1
        j = j - 1 

    print("The sorted array ")        
    print(Output)



#Verify if it works on the passed array
A = [2,5,3,0,2,3,0,3,8,9,6,6,8,7,1]
print("The unsorted array ")
print(A)
counting_sort(A,10)   #pass array and range of numbers eg:(0-5)


        
    
    
