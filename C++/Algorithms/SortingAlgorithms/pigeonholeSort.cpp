/*
* Pigeonhole sort is a non-comparison sorting algorithm that is useful when sorting integers.
*
* time complexity: O(N + n) for all cases
* n = number of elements in array
* N = the range of possible values with array to be sorted
*
* pigeonhole sort is suitable for whenever N and n are approximately the same.
*/
#include <vector>
#include <iostream>
#define MAX 100000

void pigeonholeSort(int arr[], int size) {
	// first find minimum and maximum value within array to find range
	int minVal = arr[0];
	int maxVal = arr[0];
	for (int i = 1; i < size; i++) {
		if (minVal > arr[i])
			minVal = arr[i];
		else if (maxVal < arr[i])
			maxVal = arr[i];
	}
	int range = maxVal - minVal + 1;

	//create pigeonholes and stick each element into a pigeonhole
	std::vector<int> pigeonholes(range, 0);
	for (int i = 0; i < size; i++) {
		pigeonholes[arr[i] - minVal]++;
	}
	int index = 0;

	//extracting elements from pigeonhole into sorted array 
	for (int i = 0; i < range; i++) {
		for (int j = 0; j < pigeonholes[i]; j++) {
			arr[index++] = i + minVal;
		}
	}
}

int main() {
	int size, num;
	int arr[MAX];
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	std::cout << "Enter the elements to be sorted:";
	for (int i = 0; i < size; i++) {
		std::cin >> num;
		arr[i] = num;
	}
	pigeonholeSort(arr, size);
	std::cout << "Array after sorting is: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
