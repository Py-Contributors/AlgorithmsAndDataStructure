//CPP program for Linear Queue 
#include<iostream>
#include<stdlib.h>
 
using namespace std;
 
struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear,*temp;
 
void ins()
{
	temp=new node;
	cout<<"Enter data:";
	cin>>temp->data;
	temp->next=NULL;
	
	if(front==NULL)
		front=rear=temp;
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
 
void del()
{
	if(front==NULL)
		cout<<"Queue is empty\n";
	else
	{
		temp=front;
		front=front->next;
		cout<<"Deleted node is "<<temp->data<<"\n";
		delete(temp);
	}
}
 
void dis()
{
	if(front==NULL)
		cout<<"Queue is empty\n";
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}		
	}
}
 
int main()
{
	int ch;
	while(1)
	{
		cout<<"\n\n*** Menu ***"<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit";
		cout<<"\n\nEnter your choice(1-4):";
		cin>>ch;
		cout<<"\n";
		
		switch(ch)
		{
			case 1: ins();
					break;
			case 2: del();
					break;
			case 3: dis();
					break;
			case 4: exit(0);
					break;
			default: cout<<"Wrong Choice!!!";
		}
	}
	
	return 0;
}