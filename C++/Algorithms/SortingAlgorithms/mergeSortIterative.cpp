#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
    // * Setting Up auxiliary arrays
    int n1 = m - l + 1, n2 = h - m;

    int *left = new int[n1];
    int *right = new int[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // * standard merge Logic
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    delete[] left, right;
}

// Iterative merge Sort
void mergeSort(int arr[], int n)
{
    int curr_size; // For current size of subarrays to be merged
        // curr_size varies from 1 to n/2
    int left_start; // For picking starting index of left subarray
        // to be merged

    // Merge subarrays in bottom up manner. First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        // Pick starting point of different subarrays of current size
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting
            // point of right
            int mid = min(left_start + curr_size - 1, n - 1);

            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = *(&arr + 1) - arr;

    mergeSort(arr, n);

    for (int x : arr)
        cout << x << " ";
    return 0;
}
