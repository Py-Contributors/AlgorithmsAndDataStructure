// * Complexity -> O(n^2)
// # O(n) best case
// * Stable , Inplace

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    // Base case
    if (n == 1)
        return;

    bool sorted = true;

    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            bool sorted = false;
        }

    if (sorted)
        return;

    // Largest element is fixed,
    // recur for remaining array
    BubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {12, 56, 71, 31, 10, 19, 54, 25};
    int size = *(&arr + 1) - arr;
    BubbleSort(arr, size);
    for (int x : arr)
        cout << x << " ";
    return 0;
}