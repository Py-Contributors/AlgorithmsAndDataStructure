// Kadane's Algorithm
// Algorithm for finding the max subarray sum in O(n)

#include <bits/stdc++.h>

using namespace std;

int max_subarray_sum(int A[], int n) {
    int ans = INT_MIN; // It can be set to 0 if an empty array is allowed as solution

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        ans = max(ans, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    return ans;
}

int main() {
    int A[10] = {8, 3, -5, 1, 2, 10, -8, -15, 2, 10};
    cout << max_subarray_sum(A, 10) << "\n";
}