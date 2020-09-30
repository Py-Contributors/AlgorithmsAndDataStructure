#include <iostream>
#include<bits/stdc++.h>
#include <algorithm> 
#include<map>
#include<string>
#include<unordered_map>
#include <set>
#include<cmath>
#include<math.h>
#include <unordered_set>
#include<float.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const long long mod = 1000000007;
const long long maxx = 100005;
vector<int> graph[maxx];
bool vis[maxx];

int mergeSort(vector<int>arr, vector<int> temp, int left, int right);
int merge(vector<int>arr, vector<int>temp, int left, int mid, int right);
int mergeSort(vector<int>arr, int array_size)
{
	vector<int>temp;
	return mergeSort(arr, temp, 0, array_size - 1);
}

int mergeSort(int arr[], vector<int> temp, int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;
		inv_count += mergeSort(arr, temp, left, mid);
		inv_count += mergeSort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

int merge(vector<int>arr, vector<int>temp, int left,
	int mid, int right)
{
	int i, j, k;
	int inv_count = 0;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}
int main()
{
	int n;
	cout << "Enter length of array" << endl;
	cin >> n;
	cout << "Enter array elements" << endl;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		arr.push_back(t);
	}
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}
