"""
Author: bikashhalder
The quick sort uses divide and conquer method to gain the same advantage
as the merge sort, while not using additional storage.

Worst-case performance : O(n2)
Best-case performance  : O(n log n) (simple partition)  or O(n) (three-way partition and equal keys)
Average performance    : O(n log n)
Worst-case space 
complexity	           :  O(n) auxiliary (naive)  O(log n) auxiliary (Sedgewick 1978)
"""

class QuickSort:
    def quicksort(self,list_a):
        self.helper(list_a, 0 , len(list_a) - 1)
    
    def helper(self,list_a, first, last):
        if first < last:
            split_point = self.partition(list_a, first,last)
            self.helper(list_a,first,split_point - 1)
            self.helper(list_a,split_point + 1,last)

    def partition(self,list_a, first, last):
        pivot = list_a[first]

        left = first + 1
        right = last

        done = False

        while not done:
            while left <= right and list_a[left] <= pivot:
                left = left + 1
            
            while list_a[right] >= pivot and right >= left:
                right = right - 1
            
            if right < left:
                done = True
            else:
                temp = list_a[left]
                list_a[left] = list_a[right]
                list_a[right] = temp
    
        temp = list_a[first]
        list_a[first] = list_a[right]
        list_a[right] = temp

        return right
obj = QuickSort()
a = [5,2,4,56,7,2,43,57]
obj.quicksort(a)
print(a)

#output = [2,2,4,5,7,43,56,57]