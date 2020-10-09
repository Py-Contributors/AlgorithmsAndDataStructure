/*
    Z Algorithm:
    Given a pattern and text, this 
    algorithm computes all the locations
    where pattern is present
    Time Complexity - O(n + m)
*/

#include <iostream>
using namespace std;

/* Z of i finds the length of 
    longest substring that is also
    a prefix starting from i 
*/
int *zFunction(string str)
{
    int n = str.length();
    int *z = new int[n];
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > r)
        {
            l = i;
            r = i;
            while (i < n && str[r - l] == str[r])
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] <= r - i)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && str[r - l] == str[r])
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

void zPattern(string text, string pattern)
{
    // Insert a charater that is not present in both the strings
    string str = pattern + '$' + text;
    int *z = zFunction(str);

    // Printing all the substring that have length equal to pattern
    for (int i = 0; i < str.length(); i++)
    {
        if (z[i] == pattern.length())
        {
            cout << i - pattern.length() - 1 << " ";
        }
    }
}

int main()
{
    string text = "thiscodeisourcode";
    string pattern = "code";
    zPattern(text, pattern);
    return 0;
}
