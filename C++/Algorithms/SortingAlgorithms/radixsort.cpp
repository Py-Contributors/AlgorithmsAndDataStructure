#include <iostream> 
using namespace std; 
  
// A utility function 
int FetchMax(int arr[], int n) 
{ 
    int maxm = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > maxm) 
            maxm = arr[i]; 
    return maxm; 
} 
  
// A function to do counting sort 
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = { 0 }; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radixsort(int arr[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = FetchMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
  
// A utility function to print an array 
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 17, 45, 175, 190, 502, 124, 12, 166 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
     
    radixsort(arr, n); 
    print(arr, n); 
    return 0; 
}