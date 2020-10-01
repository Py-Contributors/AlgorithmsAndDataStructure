// Binary search algorithm
// This algorithm finds the index of an element in a sorted array

#include <iostream>
using namespace std;

// Recursive approach
int binarySearchRecursive(int a[], int l, int r, int t) {
    if(l <= r) {
        // middle element
        int m = l + (r - l) / 2;

        if(a[m] == t) {
            return m;
        }
        else if(a[m] > t) {
            return binarySearchRecursive(a, l, m - 1, t);
        }
        else {
            return binarySearchRecursive(a, m + 1, r, t);
        }
    }

    // If the element is not found return -1
    return -1;
}


// Iterative approach
int binarySearchIterative(int a[], int l, int r, int t) {
    while(l <= r) {
        int m = l + (r - l) / 2;

        if(a[m] == t) {
            return m;
        }
        else if(a[m] > t) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

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