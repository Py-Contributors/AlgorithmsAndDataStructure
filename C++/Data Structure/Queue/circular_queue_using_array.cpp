#include <iostream>

using namespace std;

#define SIZE 5

int rear=-1,front=-1,cq[SIZE];

void insert();
void del();
void display();


int main()
{
    int ch;
	cout<<"0.Exit\n";
	cout<<"1.Insert\n";
	cout<<"2.Delete\n";
	cout<<"3.Display\n"; 

    do
	{
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 0:
				cout<<"Now you exit from the program";
				break;
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			default:
				cout<<"Enter right choice:";
				break;
		}
	}while(ch!=0);

    return 0;
}


void insert()
{
	int value;
	if(front==(rear+1)%SIZE)
	{
		cout<<"Queue is Overflow\n";
	}
	else
	{
		if(front==-1)
			front=0;
		cout<<"Enter value:";
		cin>>value;
		rear=(rear+1)%SIZE;
		cq[rear]=value;
	}
}

void del()
{
	int value;
	if(front==-1)
		cout<<"Queue is Underflow\n";
	else
	{
		value=cq[front];
		cout<<value<<"\n";
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=(front+1)%SIZE;
	}
}

void display()
{
	int i;
	if(front==-1)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
				cout<<cq[i]<<"\n";
		}
		else
		{
			for(i=front;i<SIZE;i++)
				cout<<cq[i]<<"\n";
			for(i=0;i<=rear;i++)
				cout<<cq[i]<<"\n";
		}
	}
}