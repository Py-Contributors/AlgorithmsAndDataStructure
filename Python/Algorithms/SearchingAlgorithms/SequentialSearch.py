# Implementation of SequentialSearch in python

# Python3 code to sequentially search key in arr[].
# If key is present then return its position,
# otherwise return -1
# If return value -1 then print "Not Found!"
# else print position at which element found


def Sequential_Search(dlist, item):
    pos = 0
    found = False
    while pos < len(dlist) and not found:
        if dlist[pos] == item:
            # check if element at current position in list matches entered key
            found = True
        else:
            pos += 1
    if found:
        return pos
    else:
        return -1


# Driver Code
list = input("Enter list elements (space seperated): ").split()
list = [int(i) for i in list]

key = int(input("Enter key to search: "))
res = Sequential_Search(list, key)

if res >= 0:
    print(f"Found element at position: {res}")
else:
    print("Not found!")
