#include<bits/stdc++.h>
using namespace std;

void printQueue(queue<int> q)
{
	while (!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main()
{
    queue<int>q;
    while(1)
    {
        cout<<"Press 1 to enqueue\n2 to dequeue \n3 to print\n0 to exit"<<endl;
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"Enter the element to be pushed"<<endl;
            int num;
            cin>>num;
            q.push(num);
        }
        if(n==2)
        {
            q.pop();
        }
        if(n==3)
        {
            printQueue(q);
        }
    }
}
