// C++ Program to find Diameter of n-ary tree 
#include <bits/stdc++.h> 
using namespace std; 

// Here 10000 is maximum number of nodes in 
// given tree. 
int diameter[10001]; 

// The Function to do bfs traversal. 
// It uses iterative approach to do bfs 
// bfsUtil() 
int bfs(int init, vector<int> arr[], int n) 
{ 
	// Initializing queue 
	queue<int> q; 
	q.push(init); 

	int visited[n + 1]; 
	for (int i = 0; i <= n; i++) { 
		visited[i] = 0; 
		diameter[i] = 0; 
	} 

	// Pushing each node in queue 
	q.push(init); 

	// Mark the traversed node visited 
	visited[init] = 1; 
	while (!q.empty()) { 
		int u = q.front(); 
		q.pop(); 
		for (int i = 0; i < arr[u].size(); i++) { 
			if (visited[arr[u][i]] == 0) { 
				visited[arr[u][i]] = 1; 

				// Considering weight of edges equal to 1 
				diameter[arr[u][i]] += diameter[u] + 1; 
				q.push(arr[u][i]); 
			} 
		} 
	} 

	// return index of max value in diameter 
	return int(max_element(diameter + 1, 
						diameter + n + 1) 
			- diameter); 
} 

int findDiameter(vector<int> arr[], int n) 
{ 
	int init = bfs(1, arr, n); 
	int val = bfs(init, arr, n); 
	return diameter[val]; 
} 

// Driver Code 
int main() 
{ 
	// Input number of nodes 
	int n = 6; 

	vector<int> arr[n + 1]; 

	// Input nodes in adjacency list 
	arr[1].push_back(2); 
	arr[1].push_back(3); 
	arr[1].push_back(6); 
	arr[2].push_back(4); 
	arr[2].push_back(1); 
	arr[2].push_back(5); 
	arr[3].push_back(1); 
	arr[4].push_back(2); 
	arr[5].push_back(2); 
	arr[6].push_back(1); 

	printf("Diameter of n-ary tree is %d\n", 
		findDiameter(arr, n)); 

	return 0; 
} 
