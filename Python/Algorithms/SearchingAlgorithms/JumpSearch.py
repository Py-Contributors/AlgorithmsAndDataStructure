"""
jump search algorithm - Implementation.

This algorithm iterates through a sorted collection of elements by
jumping ahead by fixed number of steps [n^(1/2)] until the element
compared is greater than the one searched.
Then it will perform a linear search until it found the required number.
If it is not found,then it returns -1.
"""
import math


def jumpsearch(arr, num, n):
    """Function for Jump searching."""
    step = int(math.floor(math.sqrt(n)))
    prev = 0
    while arr[min(step, n) - 1] < num:
        prev = step
        step += int(math.floor(math.sqrt(n)))
        if prev >= n:
            return -1

    while arr[prev] < num:
        prev = prev + 1
        if prev == min(step, n):
            return -1
    if arr[prev] == num:
        return prev
    return -1


# Drivers code
if __name__ == "__main__":
    user_in = input("Enter numbers separated by spaces: ").strip()
    arr = sorted([int(item) for item in user_in.split(" ")])
    num = int(input("Enter the number to be searched: "))
    n = len(arr)
    index = jumpsearch(arr, num, n)
    if index == -1:
        print("Number", num, "is not found")
    else:
        print("The sorted array is", arr)
        print("Number", num, "is found at index", index)
