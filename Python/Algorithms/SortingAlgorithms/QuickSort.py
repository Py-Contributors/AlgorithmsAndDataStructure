class QuickSort:

    
    def __init__(self,array, start, end):
        print("QuickSort Sort Algorithm is Initialized")
        self.ar = array
        self.quick_sort(array,start, end)
        print(array)
        
    def quick_sort(self, array, start, end):
        if start < end:
            pivot = self.partition(array,start,end)
            self.quick_sort(array,start,pivot-1)
            self.quick_sort(array,pivot+1,end)

    def partition(self,array,start,end):
        x = array[end]
        i = start-1
        for j in range(start, end+1, 1):
             print(array)
             if array[j] <= x:
                 i += 1
                 if i<j:
                     z = array[i]
                     array[i] = array[j]
                     array[j] = z    
        return i

sort = QuickSort()
arr = [4, 2, 6, 5, 9, 8]
n = len(arr)

print(sort(arr, 0, n-1))

