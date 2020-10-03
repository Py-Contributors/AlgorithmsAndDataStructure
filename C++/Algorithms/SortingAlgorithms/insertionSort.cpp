#include <bits/stdc++.h>
using namespace std;

/*
    Function to sort an array using Insertion Sort;
    Time Complexity : O(n*n);
    Space Complexity : O(1);
*/
void insertionSort(int arr[], int n) {

	for (int i = 1; i < n; i++) {
		int k = arr[i];
		int j = i - 1;
		while (j >= 0 and k < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = k;
	}

}

/*
    Utility Function to print elements of the array;
    Time Complexity : O(n);
    Space Complexity : O(1);
*/
void printArray(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}

int main() {

	int arr[] = {4, 7, 9, 1, 2, 3, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;

}