// Ternary Search
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to perform Ternary Search using recursion


int ternarySearchRecursive(int l, int r, int key, int ar[]) 
{ 
    if (r >= l) { 
  
        // Find the mid1 and mid2 
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
  
        // Check if key is present at any mid 
        if (ar[mid1] == key) { 
            return mid1; 
        } 
        if (ar[mid2] == key) { 
            return mid2; 
        } 
  
        // Since key is not present at mid, 
        // check in which region it is present 
        // then repeat the Search operation 
        // in that region 
        if (key < ar[mid1]) { 
  
            // The key lies in between l and mid1 
            return ternarySearch(l, mid1 - 1, key, ar); 
        } 
        else if (key > ar[mid2]) { 
  
            // The key lies in between mid2 and r 
            return ternarySearch(mid2 + 1, r, key, ar); 
        } 
        else { 
  
            // The key lies in between mid1 and mid2 
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar); 
        } 
    } 
  
    // Key not found 
    return -1; 
} 




// Function to perform Ternary Search using iteration

int ternarySearchIterative(int l, int r, int key, int ar[]) 
  
{ 
    while (r >= l) { 
  
        // Find the mid1 and mid2 
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 
  
        // Check if key is present at any mid 
        if (ar[mid1] == key) { 
            return mid1; 
        } 
        if (ar[mid2] == key) { 
            return mid2; 
        } 
  
        // Since key is not present at mid, 
        // check in which region it is present 
        // then repeat the Search operation 
        // in that region 
  
        if (key < ar[mid1]) { 
  
            // The key lies in between l and mid1 
            r = mid1 - 1; 
        } 
        else if (key > ar[mid2]) { 
  
            // The key lies in between mid2 and r 
            l = mid2 + 1; 
        } 
        else { 
  
            // The key lies in between mid1 and mid2 
            l = mid1 + 1; 
            r = mid2 - 1; 
        } 
    } 
  
    // Key not found 
    return -1; 
} 
  


int main() 
{ 
    int l1=0, r1=9, key1=5; 
  
    // Get the array 
    // Sort the array if not sorted 
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
  
    // Search the key using ternarySearch 
   int p1 = ternarySearchRecursive(l1, r1, key1, arr1); 
  
    // Print the result 
    cout << "Index of " << key << " is " << p << endl; 
  
   
   int key2 = 50; 
  
    // Search the key using ternarySearch 
 int p2 = ternarySearchRecursive(l1, r1, key2, arr1); 
  
    // Print the result 
    cout << "Index of " << key2 << " is " << p2 << endl; 

  
 
    int arr2[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }; 
  
   key1=15;
    // Search the key using ternarySearch Iterative
  int  p = ternarySearchIterative(l1, r1, key1, arr2); 
  
    // Print the result 
    cout << "Index of "<<key1<<" is " << p << endl; 
 
  
    // Search the key using ternarySearch Iterative
    p = ternarySearchIterative(l1, r1, key2, arr2); 
  
    // Print the result 
    cout << "Index of "<<key2<<" is " << p;

    return 0;
} 
