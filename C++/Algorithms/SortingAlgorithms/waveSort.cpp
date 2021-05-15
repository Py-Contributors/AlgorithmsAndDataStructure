#include <iostream>
using namespace std;

void waveSort(int *arr, int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
            swap(arr[i], arr[i - 1]);
        if (arr[i] > arr[i + 1] && i <= n - 2)
            swap(arr[i], arr[i + 1]);
    }
}

int main()
{
    int arr[] = {1, 3, 4, 7, 5, 6, 2};
    int n = *(&arr + 1) - arr;
    waveSort(arr, n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}