// C++ program for count() and find()

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // initialzing vector with array values

    int arr[] = {40, 60, 20, 90, 40, 50, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr,  arr+n);

    // count of elemen in vector
    cout << "element 90 presnet ";
    cout << count(vect.begin(), vect.end(), 90) << " times in vector";

    // find element in vector
    // ternary operator
    find(vect.begin(), vect.end(), 20) != vect.end()? 
    cout << "\nElement found":
    cout << "\nElement not found";
    
    return 0;

}