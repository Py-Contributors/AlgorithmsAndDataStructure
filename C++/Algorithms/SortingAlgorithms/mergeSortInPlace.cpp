// * Complexity -> O(N*logN)
// * Stable, In Place

#include <iostream>
using namespace std;

void merge(int *a, int l, int m, int r) // * Complexity->O(n + m)
{
    int mx = max(a[m], a[r]) + 1;
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r && k <= r)
    {
        // recover back original element to compare
        int e1 = a[i] % mx;
        int e2 = a[j] % mx;
        if (e1 <= e2)
        {
            // update element by adding multiplication with new number
            a[k] += (e1 * mx);
            i++;
            k++;
        }
        else
        {
            // update element by adding multiplication with new number
            a[k] += (e2 * mx);
            j++;
            k++;
        }
    }

    // process those elements which are left in array arr1
    while (i <= m)
    {
        int el = a[i] % mx;
        a[k] += (el * mx);
        i++;
        k++;
    }

    // process those elements which are left in array arr2
    while (j <= r)
    {
        int el = a[j] % mx;
        a[k] += (el * mx);
        j++;
        k++;
    }

    // finally update elements by dividing with maximum element
    for (int i = l; i <= r; i++)
        a[i] /= mx;
}

void MergeSort(int arr[], int l, int r)
{

    if (r > l)
    {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = *(&arr + 1) - arr;
    MergeSort(arr, 0, size - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}