def first(arr,l,r,k,n):
    if l<=r:
        mid = (l+r)//2
        if (arr[mid] == k and (mid == 0 or k > arr[mid-1])):
            return mid  
        elif (k>arr[mid]):
            return first(arr,mid+1,n-1,k,n)
        else:
            return first(arr,l,mid-1,k,n)
    return -1
def second(arr,l,r,k,n):
    
    if l<=r:
        mid = (l+r)//2
        if (arr[mid] == k and (mid == n-1 or k < arr[mid+1])):
            return mid  
        elif (k>arr[mid]):
            return second(arr,mid+1,n-1,k,n)
        elif (k<arr[mid]):
            return second(arr,l,mid-1,k,n)
    return -1


def search(arr,left,right,key,n):
    modlu = first(arr,left,right,key,n)
    if modlu == -1:
        return -1
    eradu = second(arr,modlu,right,key,n)
    return (eradu,modlu)



if __name__ == "__main__":   
   
    arr = [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 ]
    n = len(arr)
    key = 10
    left = 0
    right = n-1
    count = search(arr,left,right,key,n)
    print(count)