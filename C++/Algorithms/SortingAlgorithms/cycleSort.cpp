// * Time Complexity : O(n^2)
// * It does the minimum Memory Writes and can be used where memory writes are costly like EPROM
// * Not Stable, In Place
// # Useful to solve questions like minimum swaps required to sort an array.

#include <iostream>
using namespace std;

void cycleSort(int *arr, int n)
{
    int count = 0;
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
                pos++;
        }

        // If item is already in correct position
        if (pos == cs)
            continue;

        // ignore all duplicate  elements
        while (item == arr[pos])
            pos++;

        // put the item to it's right position
        if (pos != cs)
        {
            swap(item, arr[pos]);
            count++;
        }
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;

            // ignore all duplicate  elements
            while (item == arr[pos])
                pos++;

            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                count++;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    int arr[] = {1, 4, 2, 3, 5};
    int n = *(&arr + 1) - arr;

    cycleSort(arr, n);

    for (int x : arr)
        cout << x << " ";
    return 0;
}