# Binary Search.

def binary_search(l1, key):
    start = 0
    end = len(l1)
    while start < end:
        m = (start + end)//2
        if l1[m] > key:
            end = m
        elif l1[m] < key:
            start = m + 1
        else:
            return m
    return -1
 
 
l1 = input('Enter the sorted list of numbers: ')
l1 = l1.split()
l1 = [int(x) for x in l1]
key = int(input('The number to search for: '))
 
index = binary_search(l1, key)
if index < 0:
    print('{} was not found.'.format(key))
else:
    print('{} was found at index {}.'.format(key, index))