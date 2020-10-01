
/*
    title: all permutation of a string
    what will it do: It will generate all permutation of a string
    time complexity: O(n*n!) 
    code written and tested by: https://github.com/rafu01
    date: 10-oct-2020
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 1st approach
// the idea is to keep one part of the string fixed and swap the other parts
void permutation(string s, int left, int right)
{
    // Base case
    if (left == right)
        cout << s << endl;
    else
    {
        // swapping to create the permuation
        for (int i = left; i <= right; i++)
        {
            swap(s[left], s[i]);
            permutation(s, left + 1, right);
            swap(s[left], s[i]);
        }
    }
}
// 2nd approach
void permutationWithSTL(string s)
{
    // We first sort the string, so that it is converted to lexicographically smallest permutation
    // ascennding order
    sort(s.begin(), s.end());
    // Keep printing next permutation while there next permutation exists
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

int main()
{
    string str = "ABC";
    int n = str.size();
    permutation(str, 0, n - 1);
    permutationWithSTL(str);
    return 0;
}

/*
Recursive tree for first function. string: ABC
		 ABC
	 /        |       \
      ABC	 BAC	  CBA  --> A is fixed in ABC, B is fixed BAC, C is fiex in CBA
    /   \      /   \     /  \
 ABC	ACB   BAC  BCA  CBA  CAB --> AB in ABC, AC in ACB, BA in BAC, BC in BCA, CB in CBA, CA in CAB are fixed
 
 */
