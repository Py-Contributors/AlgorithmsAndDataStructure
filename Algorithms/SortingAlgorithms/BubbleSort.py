class BubbleSort:
    ''' BubbleSort Algorithm Implementation in Python 3.0+

    arr : Unorded list
    output : Return list in ascending order.

    Example : 
    >>> obj = BubbleSort()
    >>> obj.sort([4,2,6,5,9,8])
    [2, 4, 5, 6, 8, 9]
    '''
    def __init__(self,arr):
        self.arr = arr
    
    def sort(self,arr):
        n = len(self.arr)
        for i in range(n):
            already_sorted  = True
            for j in range(n-i-1):
                if self.arr[j] > self.arr[j+1]:
                    self.arr[j],self.arr[j+1] = self.arr[j+1],self.arr[j]
                    already_sorted  = False
            if already_sorted :
                break
        return self.arr
        