#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Implements the counting sort algorithm on an input array of integers.
 *
 * @param array - An array of integers to be sorted.
 *
 * @return An array of integers sorted in non-descending order.
 *
 * Time Complexity:
 * - O(n + k), where n is the length of the input array and k is the range of values in the input array.
 *
 * Space Complexity:
 * - O(k), where k is the range of values in the input array.
 */
vector<int> countingSort(vector<int>& array) {
    // determine the maximum value in the input array
    int max = *max_element(array.begin(), array.end());

    // initialize a count array of size max + 1 with all elements set to 0
    vector<int> count(max + 1, 0);

    // iterate over the input array and increment the count of each element's value
    for (int i = 0; i < array.size(); i++) {
        count[array[i]]++;
    }

    // modify the count array to reflect the number of elements <= each element's value
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // create a result array of size array.size() with all elements set to 0
    vector<int> result(array.size(), 0);

    // iterate over the input array backwards and place each element in its sorted position in the result array
    for (int i = array.size() - 1; i >= 0; i--) {
        result[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // return the sorted result array
    return result;
}

int main() {
    // define an example array to sort
    vector<int> array = {3, 1, 7, 4, 9, 2, 6, 5, 8, 0};

    // sort the array using countingSort
    vector<int> sortedArray = countingSort(array);

    // print the sorted array
    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << " ";
    }
    cout << endl; // expected output: 0 1 2 3 4 5 6 7 8 9

    return 0;
}
