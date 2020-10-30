#include<iostream>
using namespace std;

int ternarySearch(int array[], int start, int end, int key) {
   if(start <= end) {
      int midFirst = (start + (end - start) /3); //mid of first and second block
      int midSecond = (midFirst + (end - start) /3); //mid of first and second block
      if(array[midFirst] == key)
         return midFirst;
      if(array[midSecond] == key)
         return midSecond;
      if(key < array[midFirst])
         return ternarySearch(array, start, midFirst-1, key);
      if(key > array[midSecond])
         return ternarySearch(array, midSecond+1, end, key);
      return ternarySearch(array, midFirst+1, midSecond-1, key);
   }
   return -1;
}

int main() {
   int n, searchKey, loc;
   cout << "Enter number of items: ";
   cin >> n;
   int arr[n]; //create an array of size n
   cout << "Enter items: " << endl;

   for(int i = 0; i< n; i++) {
      cin >> arr[i];
   }

   cout << "Enter search key to search in the list: ";
   cin >> searchKey;
   if((loc = ternarySearch(arr, 0, n, searchKey)) >= 0)
      cout << "Item found at location: " << loc << endl;
   else
      cout << "Item is not found in the list." << endl;
}
