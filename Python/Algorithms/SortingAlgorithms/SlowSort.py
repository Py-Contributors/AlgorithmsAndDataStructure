"""
    This slowSort is inplace sorting algorithm for an list of integer
    The idea behind it is, 
        it divides an input list into two half, call itself into two half. and then compairs the maximum element
        of the two half. It store the maximum element of the subarray at the top of the position
        of the sub array . then it recursively call the subarray without the maximum elements. 
    
"""



def slowSort(arr, left, right):

    if left>=right:
        return 
    
    mid = (left+right)//2

    slowSort(arr, left, mid)
    slowSort(arr, mid+1, right)

    if arr[mid] > arr[right]:
        arr[mid], arr[right] = arr[right], arr[mid]
    
    slowSort(arr, left, right-1)

