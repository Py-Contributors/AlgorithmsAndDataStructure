// A dynamic programming CPP program to find
// Length of Longest Common Subtring of two strings.
#include <bits/stdc++.h>
using namespace std;

int lcs(const string &s1, const string &s2)
{
	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
	int maxLength = 0;
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				maxLength = max(maxLength, dp[i][j]);
			}
		}
	}
	return maxLength;
}

// Driver Code
int main()
{
	string str1, str2;
	cout << "Enter First String: ";
	cin >> str1;
	cout << "Enter Second String: ";
	cin >> str2;
	int m = str1.size();
	int n = str2.size();

	cout << "Length of LCS is "
	     << lcs( str1, str2, m, n );

	return 0;
}

// This code is contributed by Bhanu Pratap Singh
