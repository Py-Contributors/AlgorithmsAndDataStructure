  <p align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=666666&height=100&section=header&text=Search%20Algorithms%20In%20Python&fontSize=55%&fontColor=ffffff">
  <h2 align="center"> <img src="../../../docs/assest/image/searchalgos.png" align="center" /></h2>
</p>

## Introduction

Searching for data stored in different data structures is a crucial part of pretty much every single application.

There are many different algorithms available to utilize when searching, and each have different implementations and rely on different data structures to get the job done.

Being able to choose a specific algorithm for a given task is a key skill for developers and can mean the difference between a fast, reliable and stable application and an application that crumbles from a simple request.

* Linear Search
* Binary Search
* Jump Search
* Fibonacci Search
* Exponential Search
* Interpolation Search

## Linear Search

Linear search is one of the simplest searching algorithms, and the easiest to understand. We can think of it as a ramped-up version of our own implementation of Python's in operator.

The algorithm consists of iterating over an array and returning the index of the first occurrence of an item once it is found.

The time complexity of linear search is O(n), meaning that the time taken to execute increases with the number of items in our input list

## Binary Search

Binary search follows a divide and conquer methodology. It is faster than linear search but requires that the array be sorted before the algorithm is executed.

Assuming that we're searching for a value val in a sorted array, the algorithm compares val to the value of the middle element of the array, which we'll call mid.

* If mid is the element we are looking for (best case), we return its index.
* If not, we identify which side of mid val is more likely to be on based on whether val is smaller or greater than mid, and discard the other side of the array.
* We then recursively or iteratively follow the same steps, choosing a new value for mid, comparing it with val and discarding half of the possible matches in each iteration of the algorithm.

We can only pick one possibility per iteration, and our pool of possible matches gets divided by two in each iteration. This makes the time complexity of binary search O(log n).

## Jump Search

Jump Search is similar to binary search in that it works on a sorted array, and uses a similar divide and conquer approach to search through it.

It can be classified as an improvement of the linear search algorithm since it depends on linear search to perform the actual comparison when searching for a value.

Given a sorted array, instead of searching through the array elements incrementally, we search in jumps.

The time complexity of jump search is O(√n), where √n is the jump size, and n is the length of the list, placing jump search between the linear search and binary search algorithms in terms of efficiency.

## Fibonacci Search

Fibonacci search is another divide and conquer algorithm which bears similarities to both binary search and jump search. It gets its name because it uses Fibonacci numbers to calculate the block size or search range in each step.

Fibonacci numbers start with zero and follow the pattern 0, 1, 1, 2, 3, 5, 8, 13, 21... where each element is the addition of the two numbers that immediately precede it.
The algorithm works with three Fibonacci numbers at a time.

The time complexity for Fibonacci search is O(log n); the same as binary search. This means the algorithm is faster than both linear search and jump search in most cases.

## Exponential Search

Exponential search is another search algorithm that can be implemented quite simply in Python, compared to jump search and Fibonacci search which are both a bit complex. It is also known by the names galloping search, doubling search and Struzik search.

Exponential search depends on binary search to perform the final comparison of values. The algorithm works by:

* Determining the range where the element we're looking for is likely to be
* Using binary search for the range to find the exact index of the item

Exponential search runs in O(log i) time, where i is the index of the item we are searching for. In its worst case, the time complexity is O(log n), when the last item is the item we are searching for (n being the length of the array).

## Interpolation Search

Interpolation search is another divide and conquer algorithm, similar to binary search. Unlike binary search, it does not always begin searching at the middle.

The time complexity of interpolation search is O(log log n) when values are uniformly distributed. If values are not uniformly distributed, the worst-case time complexity is O(n), the same as linear search.

Interpolation search works best on uniformly distributed, sorted arrays. Whereas binary search starts in the middle and always divides into two, interpolation search calculates the likely position of the element and checks the index, making it more likely to find the element in a smaller number of iterations.

<p align="right">
  <img src="https://img.shields.io/badge/Language-Python-blue?style=for-the-badge">
</p>
