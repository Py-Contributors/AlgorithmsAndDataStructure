//Given a string, we have to find out all subsequences of it. 

#include <bits/stdc++.h>
using namespace std;

void generate_subsequence(char *in, char *out, int i, int j) 
{
	//base case
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	//rec case
	//include current char
	out[j] = in[i];
	generate_subsequence(in, out, i + 1, j + 1);

	//exclude current char
	generate_subsequence(in, out, i + 1, j);

}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//char input[] = "abc";
	char input[10];
	cin>>input;
	char output[10];

	generate_subsequence(input, output, 0, 0);

	return 0;
}


/*input:-
abc

output:-
abc
ab
ac
a
bc
b
c

*/
