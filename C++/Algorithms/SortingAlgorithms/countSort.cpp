#include <iostream>
using namespace std;

void countSort(int *a, int n)
{
    int k = a[0];
    for (int i = 0; i < n; i++)
        k = max(k, a[i]);

    int *count = new int[n]{0};

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    int *output = new int[n]{0};
    for (int i = n - 1; i >= 0; i--)
        output[--count[a[i]]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = output[i];

    delete[] count, output;
}

int main()
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = *(&arr + 1) - arr;
    countSort(arr, n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}