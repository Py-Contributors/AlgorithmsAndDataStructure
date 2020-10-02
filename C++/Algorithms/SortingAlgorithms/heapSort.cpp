/* For heap sort we first create a max heap of the data.
   We know that the root of the heap is largest. The root is 
   replaced with the last node and then removed.
   We again heapify the root and this process is continued. */

/* Time Complexity : O(nlogn) */

#include <iostream>
using namespace std;
#define MAX 100000

void adjust(int a[], int n, int i)
{ // to heapify the root
    while (2 * i + 1 <= n)
    {
        int j = 2 * i + 1;
        if (j + 1 <= n && a[j + 1] > a[j])
            j = j + 1;
        if (a[i] >= a[j])
            break;
        else
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
        }
    }
}
void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    { // build heap
        adjust(a, n - 1, i);
    }

    while (n > 0)
    { //  move current root to end
        int t = 0;
        t = a[0];
        a[0] = a[n - 1];
        a[n - 1] = t;
        n--;
        adjust(a, n - 1, 0); // heapify the newly formed root
    }
}

int main()
{
    int n;
    cout << "Enter the number of elments in array : ";
    cin >> n;
    int a[MAX];
    cout << "Enter the elements in heap" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heapsort(a, n);
    cout << "Sorted array is using heapsort is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
