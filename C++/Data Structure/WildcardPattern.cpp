/* Question-:given 2 strings s1 and s2.We have to match string s1 containing (*,?,characters)
to string s2 containing only characters,*/
// * can contain characters ranging from 0 to size of string
// ? can contain single string

#include<bits/stdc++.h>
using namespace std;

//Done with the help of recursion  
bool fun(string &pattern, string &text, int i, int j)
{
    if (i < 0 && j < 0)  //(Base Case)      //T.C-: O(length of string s2*length of string s2)
        return true;    //(Base Case)      //S.C-: O(length of string s2*length of string s2 + auxilliary stack space of string s1 and s2)
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int i1 = 0; i1 <= i; i1++)
        {
            if (pattern[i1] != '*')  //for the edge case if string s2 empty and s1 contains only *
                return false;
        }
        return true;
    }
    if (pattern[i] == text[j] || pattern[i] == '?')
        return fun(pattern, text, i - 1, j - 1);      //Having a similiar character and a ? is same.As ? can be replaced to the required character 
    if (pattern[i] == '*')
        return fun(pattern, text, i - 1, j) or fun(pattern, text, i, j - 1);  //first function symbolizes if the * has more than 1 characters
    return false;                                                             //second function symbolizes if the * has only 1 character  
}
bool wildcardMatching(string pattern, string text)
{
    // Write your code here.
    int n = pattern.length();
    int m = text.length();
    return fun(pattern, text, n, m);  //calling function
}
int main()               //Main Function
{
    string s;
    cin >> s;
    string s1;
    cin >> s1;
    cout << wildcardMatching(s, s1);
}
