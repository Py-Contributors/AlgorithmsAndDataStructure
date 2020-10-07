"""
Heap

The heap is an important data structure. It provides the following
functionality:

findMin: Find the minimum of all the current data. O(1) runtime.

pop: Remove the minimum element from the current data and return it. O(log n)
runtime.

push: Add an element to the current data. O(log n) runtime.

The provided runtimes assume that the heap currently has n elements and that
checking less than on elements runs in O(1) time.

Implementation:

Our implementation of a heap will be done with arrays, and we will treat the
array as a binary tree. Each index, i, in the array will have a left and right
"child" indicies at 2i + 1 and 2i + 2 respectively. The heap operates under the
assumption of an important invariant:

For all indicies i, the value at index i is less than the values at either of
its children (2i + 1 and 2i + 2).

When we want to findMin we just return the value at index 0 in the array, the
root of our tree. This must be the minimum due to the tree structure of the
heap, and the transittivity of less than.

When we add an element to the tree, we will add it to the end of the array,
lets say at index i. We can calculate its parent index, p = (i - 1) // 2 since
it will be either the left or right child of p. If the new value is less than
the value at p, we can swap the values at p and i. We dont have to check down
the other child of the parent, since less than is transitive.

We then bubble up, and check that the parent of p satisfies the invariant as
well, and we swap if it doesn't. At each step we half our index, so this
bubble-up-ing runs in O(log n) time.

When we remove the minimum from the heap, we record the current minimum to
return later, and then replace it with the last value in the array. Then we
perform another bubbling operation, but now in the opposite direction.

We find the index of the minimum value out of the node itself and its two
children. If the minimum is the node itself, we are done. If instead it is one
of the children, we swap the parent and minimum values, and keep bubbling down
from the child.
"""


def __up(arr, index):
    """
    Bubbles the value arr[index] up to retain heap structure.
    """
    while index > 0 and arr[index] < arr[(parent := (index - 1) // 2)]:
        arr[index], arr[parent] = arr[parent], arr[index]
        index = parent


def __down(arr, index):
    """
    Bubbles the value arr[index] down to retain heap structure.
    """
    n = len(arr)
    while index < n:
        # The index of the minimum value will be kept in extreme
        extreme = index
        left = index * 2 + 1
        right = index * 2 + 2

        if left < n and arr[left] < arr[extreme]:
            extreme = left
        if right < n and arr[right] < arr[extreme]:
            extreme = right

        if extreme == index:
            break

        arr[index], arr[extreme] = arr[extreme], arr[index]
        index = extreme


def heapify(arr):
    """
    We can re-arrange any array to enforce the invariant.
    """
    for i in range(len(arr) - 1, -1, -1):
        __down(arr, i)


def findMin(heap):
    """
    Returns the minimum element in the heap.
    """
    if len(heap) == 0:
        raise IndexError("findmin on empty heap")
    return heap[0]


def heappop(heap):
    """
    Removes the head element from heap, and then rearranges the result to
    retain the heap invariant.
    """
    if len(heap) == 0:
        raise IndexError("pop from empty heap")
    if len(heap) == 1:
        # We can return the only remaining value.
        return heap.pop()
    result = heap[0]
    heap[0] = heap.pop()
    __down(heap, 0)
    return result


def heappush(heap, value):
    """
    Adds a new element to the heap, then rearranges to retain the heap
    invariant.
    """
    heap.append(value)
    __up(heap, len(heap) - 1)


def heappushpop(heap, value):
    """
    If we pop and push successively, we can simplify the process by only
    bubbling once.
    """
    if len(heap) == 0:
        raise IndexError("pop from empty heap")
    result = heap[0]
    heap[0] = value
    __down(heap, 0)
    return result


class Heap:
    """
    This class is a wrapper for the individual methods implemented above.

    It might help to realise you don't have to implement it with a class, you
    can just implement it with an array and make sure to keep the heap
    invariant.
    """

    def __init__(self):
        self.__arr = []

    def findMin(self):
        return findMin(self.__arr)

    def push(self, value):
        heappush(self.__arr, value)

    def pop(self):
        return heappop(self.__arr)

    def pushpop(self, value):
        return heappushpop(self.__arr, value)
