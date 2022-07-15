
/* 바이너리 서치 알고리즘 cpp */
// Binary search algorithm
// This algorithm finds the index of an element in a sorted array
// Time complexity : O(log n)
// Space complexity :
//      1. Recursive approach : O(log n)
//      2. Iterative approach : O(1)

#include <iostream>
#include <vector>
using namespace std;

// Recursive approach
int binarySearchRecursive(const vector<int> &a, int l, int r, int t)
{
    if (l <= r)
    {
        // middle element
        int m = l + (r - l) / 2;

        if (a[m] == t)
        {
            return m;
        }
        else if (a[m] > t)
        {
            return binarySearchRecursive(a, l, m - 1, t);
        }
        else
        {
            return binarySearchRecursive(a, m + 1, r, t);
        }
    }

    // If the element is not found return -1
    return -1;
}

// Iterative approach
int binarySearchIterative(const vector<int> &a, int l, int r, int t)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (a[m] == t)
        {
            return m;
        }
        else if (a[m] > t)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return -1;
}

int main()
{
    //For fast input output
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n;
    cout << "Please enter the number of elements in the array\n";
    cin >> n;
    cout << "Enter the sorted elements: ";
    vector<int> a(n);
    
    for (size_t i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to find";
    int t;
    cin >> t;

    cout << "By recursive approach the index of element " << t << " is : ";
    //\n is faster than endl
    cout << binarySearchRecursive(a, 0, n - 1, t) << "\n";

    cout << "By iterative approach the index of element " << t << " is : ";
    cout << binarySearchIterative(a, 0, n - 1, t) << "\n";

    return 0;
}
