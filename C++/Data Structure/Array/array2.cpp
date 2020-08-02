// A C++ program to demonstrate working of sort(), 
// reverse() 
#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <numeric> //For accumulate operation 
using namespace std; 

int main() 
{ 
	// Initializing vector with array values 
	int arr[] = {10, 20, 5, 23 ,42 , 15}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Size of Array : " << n <<endl;

	vector<int> vect(arr, arr+n);
	
	// Vector before sorting

	cout << "Vector is : ";
	for(int i=0;i<n;i++){
		cout << vect[i] << " ";
	}

	// sorting the vector in ascending order

	sort(vect.begin(), vect.end());
	cout << "\nVector after sorting : ";
	for(int i=0;i<n;i++) {
		cout << vect[i] << " ";
	}

	// Reversing the Vector

	reverse(vect.begin(), vect.end());

	cout << "\nVector after Reversing : ";
	for(int i=0;i<n;i++) {
		cout << vect[i] << " ";
	}

	// Maximum element of vectoe
	cout << "\nMaximum element of Vector : ";
	cout << *max_element(vect.begin(), vect.end());

	// Minimum element of Vecotr
	cout << "\nMinimum element of Vector : ";
	cout << *min_element(vect.begin(), vect.end());

	// Summation of vector
	cout << "\nThe summation of vector element is : ";
	cout << accumulate(vect.begin(), vect.end(), 0);

	return 0;
}