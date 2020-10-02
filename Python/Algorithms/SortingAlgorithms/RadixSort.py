class RadixSort:
    """ RadixSort Algoritm Implementation in Python 3.0+

        arr: Unorded list
        output: Return list in ascending order.
        time complexity: O(kn)

        Exmaple:
        >>> sort = RadixSort()
        >>> sort([5, 2, 1, 6, 10])
        [1, 2, 5, 6, 10]"""

    def __init__(self):
        print("Radix sort algorithm is initialized")

    def __call__(self, arr):
        maxLength = False
        tmp = -1
        placement = 1

        while not maxLength:
            maxLength = True
            buckets = [list() for _ in range(10)]

            for i in arr:
                tmp = int(i / placement)
                buckets[tmp % 10].append(i)
                if maxLength and tmp > 0:
                    maxLength = False
            a = 0
            for b in range(10):
                buck = buckets[b]
                for i in buck:
                    arr[a] = i
                    a += 1
            placement *= 10

        return arr


sort = RadixSort()
print(sort([5, 2, 1, 6, 10]))
