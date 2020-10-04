#include <iostream>

using namespace std;

int search(int arr[], int);

int main()
{
    int arr[100];

    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index = search(arr, sizeof(arr) / sizeof(int));
    
    if(index == -1) {
        cout << "Not Found";
    } else {
        cout << "Found On index " << index + 1 << ".";
    }
    return 0;
}

int search (int arr[], int length) {
    int ele;
    cout << "Enter element to search : ";
    cin >> ele;
    for (int i = 0; i < length; i++) {
        if(arr[i] == ele) {
            return i;
        }
    }
    return -1;
}
