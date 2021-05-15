// * Complexity -> O(n^2)
// # O(n) best case
// * Stable, In place
// ? Used in practice for small arrays (Tim sort and Intro Sort)

#include <iostream>
using namespace std;
//* Insert an element from unsorted array to its correct position in sorted array
void InsertionSort(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    InsertionSort(arr, n - 1);

    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n - 1];
    int j = n - 2;

    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    int arr[] = {12, 56, 71, -2, 10, 19, 54, 25};
    int size = *(&arr + 1) - arr;
    InsertionSort(arr, size);
    for (int x : arr)
        cout << x << " ";
    return 0;
}