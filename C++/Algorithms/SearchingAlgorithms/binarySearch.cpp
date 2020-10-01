// Binary search algorithm
// This algorithm finds the index of an element in a sorted array
// Time complexity : O(log n)
// Space complexity :
//      1. Recursive approach : O(log n)
//      2. Iterative approach : O(1)

#include <iostream>
using namespace std;

// Recursive approach
int binarySearchRecursive(int a[], int l, int r, int t) {
    if(l <= r) {
        // index of middle element
        int m = l + (r - l) / 2;

        if(a[m] == t) {
            // if value of middle element matches the required value then return the value of mid index
            return m;
        }
        else if(a[m] > t) {
            // if value of middle element is greater than required value then the pass l parameter as (mid index - 1) i.e. m-1
            return binarySearchRecursive(a, l, m - 1, t);
        }
        else {
            // if value of middle element is less than required value then the pass r parameter as (mid index + 1) i.e. m-1
            return binarySearchRecursive(a, m + 1, r, t);
        }
    }

    // If the element is not found return -1
    return -1;
}


// Iterative approach
int binarySearchIterative(int a[], int l, int r, int t) {
    while(l <= r) {
        
        //firstly we find the value of mid index
        int m = l + (r - l) / 2;

        //now we compare value at mid index with required value
        if(a[m] == t) {
            // if the value matches then return the mid index
            return m;
        }
        else if(a[m] > t) {
            // if value at mid index is greater than required value at mid index then we shift r to mid index - 1 i.e. m-1
            r = m - 1;
        }
        else {
            // if value at mid index is less than required value at mid index then we shift l to mid index + 1 i.e. m+1
            l = m + 1;
        }
    }
    
    // If the element is not found return -1
    return -1;
}

int main() {
    int n = 10;
    int a[n] = {23, 37, 45, 67, 76, 78, 90, 93, 99, 100};
    int t = 37;

    cout<<"By recursive approach the index of element "<<t<<" is : ";
    cout<<binarySearchRecursive(a, 0, n - 1, t)<<endl;

    cout<<"By iterative approach the index of element "<<t<<" is : ";
    cout<<binarySearchIterative(a, 0, n - 1, t)<<endl;

    return 0;
}
