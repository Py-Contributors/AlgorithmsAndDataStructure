// C++ program erase()

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int arr[] = {5, 11, 15, 20, 25, 30, 35, 40, 5, 10, 15, 20, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect (arr, arr+n);

    // print vector 
    cout << "Print vector : ";
    for(int i=0;i<n;i++) {
        cout << vect[i] << " ";
    }

    // delete second element of vector; indexing start with 0 in array
    vect.erase(vect.begin()+1);

    cout << "\nVector after erase : ";
    for(int i=0;i<n;i++) {
        cout<< vect[i] << " ";
    }

    // sorting to enable use of unique()
    sort(vect.begin(), vect.end());

    // delete the duplicate value
    vect.erase(unique(vect.begin(), vect.end()), vect.end());

    cout << "\nvector after removing duplicate values : ";
    for(int i=0;i<n;i++) {
        cout << vect[i] << " ";
    }
    cout <<endl;
    return 0;
}