// Dynamic Programming Solution Optimized for Subset Sum Count

// Example and Description: A set of positive integers is given (i.e. {1, 2, 4}) as well as a sum (i.e. 3).
// Return a boolean evaluated based on if there exists a subset (i.e. {1, 2}), or not, of
// the given set that adds up to the provided sum. The example provided evaluates to true.

// Time Complexity: O(n^2)

#include <iostream>
#include <vector>

using namespace std;

bool subsetSumCount(vector<int> vector, int currentElement, int sum) {

    if (sum == 0) {
        return true;
    }

    if (currentElement < 0 || sum < 0) {
        return false;
    }

    bool includeValue = subsetSumCount(vector, currentElement - 1, sum - vector.at(currentElement));

    bool excludeValue = subsetSumCount(vector, currentElement - 1, sum);

    return includeValue || excludeValue;

}

int main() {

    int size;
    int sum;
    int tempValue;
    vector<int> vector;
    cout<<"How many numbers do you want in the set? "<<endl;
    cin>>size;
    cout<<"What sum would you like us to find a subset for? "<<endl;
    cin>>sum;
    for (int i = 0; i < size; i++) {
        cout << "Input Value " << (i + 1) << ":"<< endl;
        cin>>tempValue;
        vector.push_back(tempValue);
    }

    if (subsetSumCount(vector, size - 1, sum)) {
        cout << "The set DOES have a subset that adds up to the given sum!";
    }
    else {
        cout << "The set does NOT have any subsets equal to the given sum.";
    }

}