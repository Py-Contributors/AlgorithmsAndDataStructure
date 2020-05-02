def insertionSort(arr):
    ''' insertionSort Algorithm Implementation in Python 3

    arr : Unorded list
    output : Return list in ascending order.
    time complexity : O(n2)
    
    Example : 
    >>> 
    >>> insertionSort([4,2,6,5,9,8])
    [2, 4, 5, 6, 8, 9]'''
    for i in range(1,len(arr)):
        key_item = arr[i]

        j = i - 1

        while j >= 0 and arr[j] > key_item:
            arr[j+1] = arr[j]
            j -= 1
        
        arr[j + 1] = key_item
        
    return arr