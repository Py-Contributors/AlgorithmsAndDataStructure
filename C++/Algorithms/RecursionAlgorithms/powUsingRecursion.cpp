// C++ program to calculate pow(a,b)

#include <iostream>
using namespace std;

int power(int a, int b)
{
	//base case
	if (b == 0)
		return 1;

	//recursive cases
	if (b % 2 == 0) //b is even
	{
		return power(a, b / 2) * power(a, b / 2);
	}
	else //b is odd
	{
		return a * power(a, b / 2) * power(a, b / 2);
	}
}

int main()
{
	int a, b;
	cout << "Enter the base and exponent: ";
	cin >> a >> b;
	cout << power(a, b) << endl;
	return 0;
}
/* 
ex:-
Enter the base and exponent: 2 3
8 
*/