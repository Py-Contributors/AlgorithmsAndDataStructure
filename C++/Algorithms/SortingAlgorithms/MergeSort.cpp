#include <iostream>
using namespace std;
 
// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, res[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			res[k] = a[i];
			k++;
			i++;
		}
		else
		{
			res[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into res[].
	while (i <= mid)
	{
		res[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into res[].
	while (j <= high)
	{
		res[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in res[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = res[i-low];
	}
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
 
int main()
{
// 	Title - Bubble sort Algorithm
//         It will sort array
//         time complexity -O(nlogn) 
	int arr[5]={5,1,3,4,2};
	MergeSort(arr, 0, n-1);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];
 
	return 0;
}
