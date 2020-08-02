//  lower bound and upper bound in vectors

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // initialize vectors 
    int arr[] = {40, 30, 80, 50, 90, 20, 30, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);

    // sort array to make sure that lower_bound and upper_bound work.
    sort(vect.begin(), vect.end());

    // returns the first occurrence of 20
    auto p = lower_bound(vect.begin(), vect.end(), 30);
    auto q = upper_bound(vect.begin(), vect.end(), 30);

    cout << p-vect.begin() << endl;
    cout << q-vect.begin();

    return 0;
}