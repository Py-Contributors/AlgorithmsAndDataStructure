/* Merge Sort is is a Divide and Conquer algorithm. 
   The array is recursively divided the array in two halves till the size becomes 1.
   Then the array is merged in arranged order. */

/* Time complexity : O(nlogn) in all cases
   Space complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

void merge(int arr[], int l, int m, int r) // fn for merging the elements in sorted manner.
{
    int i, j, k;
    int n1 = m - l + 1; // elements in LHS
    int n2 = r - m;     // elements in RHS

    int L[n1], R[n2]; // temporary arrays

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int *a, int low, int high) //recursive calls for dividing array
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[MAX];
    int n, num;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[i] = num;
    }
    mergeSort(a, 0, n - 1);
    cout << "The sorted elements are : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
