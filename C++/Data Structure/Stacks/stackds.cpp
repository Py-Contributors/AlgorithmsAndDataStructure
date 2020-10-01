//C++ Program to implement Stack Data Structure
#include <iostream>
#include<list>

using namespace std;

template <class T>
class stack
{
	list<T> obj;
public:
	void push() // to push the element in the stack
	{
		T n;
		cout<<"\n Enter any number :";
		cin>>n;
		obj.push_back(n);
	}
	void pop()  // to pop the element from the stack
	{
		cout<<"\n Poped Element is :"<<obj.back();
		obj.pop_back();
	}
};

template<class T>
void menu(stack<T> obj) // menu driven program
{
	int x=0;
	do
	{
		cout<<"\n Menu ";
		cout<<"\n 1) Push ";
		cout<<"\n 2) Pop ";
		cout<<"\n 3) Back to main menu";
		cout<<"\n ENter your choice:";
		cin>>x;
		switch(x)
		{
		case 1:
			obj.push();
			break;
		case 2:
			obj.pop();
			break;
		case 3:
			break;
		default :
			cout<<"\n Invalid input ";
		}
	}while(x!=3);
}


int main()
{
	int x=0;
	do
	{
		cout<<"\n Menu ";
		cout<<"\n 1) Double ";
		cout<<"\n 2) Float ";
		cout<<"\n 3) Character";
		cout<<"\n 3) Exit";
		cout<<"\n ENter your choice:";
		cin>>x;
		switch(x)
		{
		case 1:
			//stack<int> obj;
			//menu(obj);
			break;
		case 2:
			stack<int> obj1;
			menu(obj1);
			break;
		}
	}while (x!=3);

	return 0;
}
