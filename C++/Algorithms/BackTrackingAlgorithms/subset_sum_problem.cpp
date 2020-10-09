/*
To find a subset of an array whose sum is 
equal to a specified number.
Using Backtracking Approach.
Time Complexity: - Worst case O(2^n)
Space Complecity: - O(1)
*/

#include <bits/stdc++.h>

using namespace std;

// BACKTRACKING ALGORITHM
void subsetsum(int Set[], int pos, int sum, int tmpsum, int size, bool & found)
{
    if (sum == tmpsum)
    {
        found=true;;
    }

    // generate nodes along the breadth
    for (int i = pos; i < size; i++)
    {
        if (tmpsum + Set[i] <= sum)
        {
            tmpsum += Set[i];
            // consider next level node (along depth)
            subsetsum(Set, i + 1, sum, tmpsum, size, found);
            tmpsum -= Set[i];
        }
    }
}

int main()
{
    int i, n, sum;
    bool found =false;  
    cout << "Enter the number of elements in the set" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the values of set" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the value of sum" << endl;
    cin >> sum;
    subsetsum(a, 0, sum, 0, n, found);
    if (found)
        cout << "subset with the given sum found" << endl;
    else
        cout << "no required subset found" << endl;
    return 0;
}
