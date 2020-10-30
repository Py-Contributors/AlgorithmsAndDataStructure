class QuickSort:
    def partition(self, arr, low, high):
        i = (low-1)         # index of smaller element
        pivot = arr[high]     # pivot

        for j in range(low, high):

            # If current element is smaller than or
            # equal to pivot
            if arr[j] <= pivot:

                # increment index of smaller element
                i = i+1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i+1], arr[high] = arr[high], arr[i+1]
        return (i+1)

    # Function to do Quick sort
    def quickSort(self, arr, low, high):

        if len(arr) == 1:
            return arr
        if low < high:

            # pi is partitioning index, arr[p] is now
            # at right place
            pi = self.partition(arr, low, high)

            # Separately sort elements before
            # partition and after partition
            self.quickSort( arr, low, pi-1)
            self.quickSort( arr, pi+1, high)
        return arr


# Driver code to test above
# arr = [20, 13, 7, 6, 2, 3]
# n = len(arr)
# c = QuickSort()
# print("Sorted array is:", c.quickSort(arr, 0, n-1))
