'''
Title- Subset Sum Problem
it will give the subsets of a given aum and array
'''


def printAllSubsetsRec(arr, n, v, sum):
    # If remaining sum is 0, then print all
    # elements of current subset
    if (sum == 0):
        print(v)
        return

    # If no remaining elements
    if (n == 0):
        return

    # We consider two cases for every element
    # a) We do not include last element
    # b) We include last element in current subset
    printAllSubsetsRec(arr, n - 1, v, sum)
    v1 = [] + v
    v1.append(arr[n - 1])
    printAllSubsetsRec(arr, n - 1, v1, sum - arr[n - 1])


# Driver code
arr = []
i = int(input("Enter the number of elements in array: "))
for j in range(0, i):
    arr.append(int(input("enter the element of the array: ")))
sum = int(input("Enter the value of sum: "))
v = []
printAllSubsetsRec(arr, len(arr), v, sum)
