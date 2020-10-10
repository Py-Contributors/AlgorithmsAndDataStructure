#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {

    /* run loops two times
     * one for walking through the array
     * and the other for comparison 
     */

    for(int step=0;step-size-1;step++){
        bool swapped = false;
        for(int i=0;i<size-step-1;i++) {

            if(array[i] > array[i+1]) {
                swapped = true;
                // swap if greater is at the rear position
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        if (!swapped)
          break;
    }
}

void printArray(int array[], int size) {
    for(int i = 0;i<size;i++) {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main() {
    /* 
    BubbleSort Algorithm Implementation in C++

        array : Unorded list
        output : Return list in ascending order.
        time complexity : O(n2)
     */
    int data[] = {10, 34, 0, 45, -10};
    int size = sizeof(data)/sizeof(data[0]);

    bubbleSort(data, size);
    cout << "Sorted array in ascending order :\n";
    printArray(data, size);
}
