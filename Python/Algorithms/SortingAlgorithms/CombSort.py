"""
CombSort Algorithm Implementation in Python 3

    arr : Unorded list
    output : Return list in ascending order.
    time complexity : Worst case complexity is O(n^2)
                      Best Case complexity is O(n)
"""


def combsort(arr, n):
    gap = n
    while gap > 1:
        gap = int(gap / 1.3)
        for i in range(0, n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
    return arr


a = int(input("Enter the number of elements in the array: "))
li = []
for i in range(0, a):
    li.append(int(input('Enter the element one at a time: ')))
print('The unsorted array you have given is:', li)
print('The sorted array using combsort method is: ', end="")
print(combsort(li, len(li)))
