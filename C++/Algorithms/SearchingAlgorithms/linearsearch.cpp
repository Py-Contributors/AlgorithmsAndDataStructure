#include<iostream>
 
using namespace std;
 
int main()
{
	int a[20],n,x,i,flag=0;
	cout<<"Enter number of elements in array\n";
	cin>>n;
	cout<<"\nEnter elements of the array\n";
	
	for(i=0;i<n;++i)
		cin>>a[i];
	
	cout<<"\nEnter element to search:";
	cin>>x;
	
	for(i=0;i<n;++i)
	{
		if(a[i]==x)
		{
			flag=1;
			break;
		}
	}
	
	if(flag)
		cout<<"\nElement is present at position "<<i+1;
	else
		cout<<"\nElement isn't present in the array";
		
	return 0;
}
