/*
    * Selection Sort Implementation in C++    
*/
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, minIndex;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        // Swap the found minimum element with the first element
        swap(&arr[minIndex], &arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main()
{
    /* 
    Selection Sort Algorithm Implementation in C++
        input : Unordered array
        output : Return list in ascending order.
        time complexity : O(n^2)
    */
    int n;
    cout << "Enter the number of Elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the Array elements\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}

/*

Test Case: 

4
56 76 32 90

Output:

32 56 76 90

*/