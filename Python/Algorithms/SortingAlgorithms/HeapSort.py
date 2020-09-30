class HeapSort:
    
    """ Heap sort Algorithm Implementation in Python 3
       >> Heap sort is a comparison based sorting technique based on Binary Heap data structure
       >> Input data: 4, 10, 3, 5, 1
       >> The numbers in bracket represent the indices in the array representation of data.


       Input         Heapify at index:0       Heapify at index:1
        4(0)                4(0)                  10(0)     
        /   \               /   \                 /   \
     10(1)   3(2)   =>     10(1) 3(2)   =>      5(1)  3(2) 
    /   \                /    \                 /   \
 5(3)    1(4)          5(3)  1(4)              4(3) 1(4) 

    """
    
    def __init__(self):
        print("Heap Sort Algorithm is Initialized")
    
    def heapify(self,arr,n,i):
        largest = i
        l = 2*i +1
        r = 2*i +2
        
        if(l < n and arr[i] < arr[l]):
            largest = l
        if r < n and arr[largest] < arr[r]:
            largest = r
        if largest != i:
            arr[i],arr[largest] = arr[largest],arr[i] 
            self.heapify(arr, n, largest)
            
    def __call__(self,arr):
        n = len(arr)
        
        for i in range(n, -1, -1):
            self.heapify(arr, n, i)
        for i in range(n-1, 0, -1):
            arr[i], arr[0] = arr[0], arr[i] 
            self.heapify(arr, i, 0)

            
        
    
             
#Driver code to call the main function
sort=HeapSort()
arr = [ 12, 11, 13, 5, 6, 7] 
sort.__call__(arr) 
n = len(arr) 
print ("Sorted array is") 
for i in range(n): 
	print ("%d" %arr[i]),  




 