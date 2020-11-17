// Interpolation Search Algorithm
// This algorithm is used to search for an element in sorted array
// returns the index of element if present, else returns -1
// This algorithm is improvement to binary search
// Time Complexity: O(log log n)) for uniformly distributed arrays, worst case time complexity is O(n).
// Space Complexity:
//   1) O(1) (iterative method)
//   2) Consumes recursion stack memory O(log log n)), worst case O(n)


// Let arr be the array, where element is to be searched
// The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[hi]. And
// smaller value when closer to arr[lo]
// pos = lo + [(x - arr[lo]) * (hi - lo) / (arr[hi] - arr[Lo])]

// C++ implementation of interpolation search
#include <iostream>
#include <vector>
using namespace std;

// Iterative Implementation of Interpolation Search
int interpolationSearchIterative(vector<int> arr, int n, int x)
{
    // indexes of 1st and last elements
    int lo = 0, hi = (n - 1);

    // Since array is sorted, an element present
    // in array must be in between first and last element
    // Here lo and hi are indices of first and last elements in range
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x)
                return lo;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = lo + (((double)(hi - lo) /
                         (arr[hi] - arr[lo])) *
                        (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;

        // If x is smaller, x is in the lower part
        else
            hi = pos - 1;
    }
    // If target element is not present, returns -1
    return -1;
}

// Recursive Implementation of Interpolation Search
int interpolationSearchRecursive(vector<int> arr, int lo, int hi, int x)
{
    int pos;

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    // Here arr[lo] and arr[hi] are corners
    if (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {

        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo + (((double)(hi - lo) /
                     (arr[hi] - arr[lo])) *
                    (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearchRecursive(arr, pos + 1, hi, x);

        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearchRecursive(arr, lo, pos - 1, x);
    }
    // If target element is not found, returns -1
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    cout << "Enter elements of array in sorted manner ";
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to be found ";
    int t;
    cin >> t;

    int a1, a2;

    //Calling Recursive Implementation
    cout << "By recursive approach " << endl;
    a1 = interpolationSearchRecursive(a, 0, n - 1, t);

    if (a1 == -1)
        cout << "Element not found \n";
    else
        cout << "Element " << t << " is present at index " << a1 <<"\n";

    //Calling Iterative Implementation
    cout << "By iterative approach\n";
    a2 = interpolationSearchIterative(a, n, t);

    if (a2 == -1)
        cout << "Element not found \n";
    else
        cout << "Element " << t << " is present at index " << a1 << "\n";

    return 0;
}