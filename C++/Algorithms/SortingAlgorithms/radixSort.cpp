// * Time Complexity:  O(d*(n+b))
// * Space Complexity: O(n+b)

// ?  Is Radix Sort preferable to Comparison based sorting algorithms like Quick - Sort ?
// -> If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers.The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick - Sort uses hardware caches more effectively.Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.

#include <iostream>
using namespace std;

void countSort(int *a, int n, int exp)
{
    int count[10] = {0};
    int *output = new int[n]{0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        output[--count[(a[i] / exp) % 10]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = output[i];

    delete[] output;
}

void radixSort(int *a, int n)
{
    int mx = a[0];
    for (int i = 0; i < n; i++)
        mx = max(mx, a[i]);

    // countSort for Every Digit
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main()
{
    int arr[] = {319, 212, 6, 8, 100, 50};
    int n = *(&arr + 1) - arr;
    radixSort(arr, n);

    cout << (465 / 20) % 20 << endl;

    for (int x : arr)
        cout << x << " ";
    return 0;
}