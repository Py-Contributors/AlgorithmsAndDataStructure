class patienceSort:
    """ Patience Sort Algorithm Implementation in Python 3.0+
        arr : Unorded list
        output : Returns one of the longest increasing subsequence.
        time complexity : O(nlogn)
    """

    def __init__(self):
        print("Patience Sort Algorithm is Initialized")

    def __call__(self, arr):
        piles = list()

        def getPile(num):
            left = 0
            right = len(piles) - 1
            index = -1

            while left <= right:
                mid = left + (right - left) // 2

                if piles[mid][-1] >= num:
                    index = mid
                    right = mid - 1
                else:
                    left = mid + 1
            return index

        for num in arr:
            index = getPile(num)
            if index == -1:
                piles.append([num])
            else:
                piles[index].append(num)
        return [x[-1] for x in piles]


sort = patienceSort()
print(sort([10, 9, 5, 11, 2]))
