/* 
    * distance(first_iterator, desired_position) : It returns the distance of desired position from 
    * the first iterator. 
    * This function us very useful while finding the index.
*/
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    // initialize vector with array values
    int arr[] = {5, 10, 15, 20, 90 , 23, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);

    // Return distance of first to maximum element
    cout << "Distance between first to max element : ";
    cout << distance(vect.begin(),
                    max_element(vect.begin(), vect.end()));
    
    return 0;
}