/*
    Find the maximum product of two distinct numbers in a sequence of non-negative integers
    Input: A sequence of non-negative integers
    Output: The maximum value that can be obtained by multiplying two different elements from the sequence.
    Input format. The first line contains an integer n. The next line contains n non-negative integers a1, . . . , an (separated by spaces).
    Output format. The maximum pairwise product
    Constraints. 2 ≤ n ≤ 2·10^5 ; 0 ≤ a1, . . . , an ≤ 2·10^5.
    Time limit: 1 sec
    Memory Limit: 512 Mb
    Sample Input 1:
        3
        1 2 3
    Sample Output 1:
        6
    Sample Input 2:
        10
        7 5 14 2 8 8 10 1 2 3
    Sample Output 2:
        140
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;

// Naive algorithm to find the Maximum Pairwise Product. Takes O(n^2)
int64_t MaxPairwiseProductNaive(const std::vector<int64_t>& numbers) {
    int64_t max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
               (int64_t)( numbers[first] * numbers[second]));
        }
    }

    return max_product;
}

// Faster solution to the Maximum Pairwise Product Problem. Takes O(nlogn)
int64_t MaxPairwiseProduct(std::vector<int64_t>& numbers) {
    int n = numbers.size();
    sort(numbers.begin(), numbers.end());
    return numbers[n - 1] * numbers[n - 2];
}

// Function to stress test the problem
void stressTest(int64_t N, int64_t M) {
    while(true) {
        int64_t n = rand() % (N - 1) + 2;
	    std::cout << "\n"  << n << "\n";	
	    vector<int64_t> A(n);
       	for (int64_t i = 0; i < n; i++) {	
	        A[i] = rand() % (M + 1);
	    }	
	    for (int64_t i = 0; i < n; i++) {
	        cout << A[i] << " ";
	    }
	    int64_t result1 = MaxPairwiseProductNaive(A);
	    int64_t result2 = MaxPairwiseProduct(A);
	    if (result1 == result2) {
	        cout << "\nOK" << "\n";
	    } else {
	        cout << "\nWrong Answer: " << result1 << " " << result2 << "\n";
	        return;  
	    }
    }
}

int main() {
    // To test the code, uncomment the following line and comment rest of the code in the main function.
    // Feel free to play around with the values in the parameter
    // stressTest(1000, 200000);
    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}