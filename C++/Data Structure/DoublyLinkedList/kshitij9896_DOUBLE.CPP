#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int cnt;
class doublelist
{
  struct node
    {
      int info;
      node *next,*prev;
    };
    struct node *start,*ptr,*temp,*i,*x;

 public:
	linkedlist()
	{
	  start=NULL;
	 }

	 void create();
	 void infront();
	 void inend();
	 void delend();
	 void delpos();
	 void display();
     };


      void doublelist::create()
      {
	int no;
	cout<<"\nEnter no:";
	cin>>no;
	ptr=new node;
	ptr->info=no;
	ptr->next=NULL;
	ptr->prev=NULL;
	ptr->next=NULL;

	if(start==NULL)
	 {
	    start=ptr;
	    temp=ptr;
	 }
	 else
	   {
	     temp->next=ptr;
	     ptr->next=NULL;
	     ptr->prev=temp;
	     temp=ptr;
	     }
	     cout<<"node inserted";
	     }


	      void doublelist::infront()
	   {
	    int no;
	    cout<<"\n Enter no:";
	    cin>>no;
	    ptr=new node;
	    ptr->info=no;
	    ptr->prev=NULL;
	    ptr->next=start;
	    start->prev=ptr;
	    start=ptr;
	    cout<<"Inserted at the beginning";
	  //  cnt++;
	   }

	    void doublelist::inend()
	   {
	    int no;
	    cout<<"\n Enter no:";
	    cin>>no;
	    ptr=new node;
	    ptr->info=no;
	     ptr->prev=temp;
	    ptr->next=NULL;
	    temp->next=ptr;
	    temp=ptr;
	    cout<<"Inserted at the end";
	   // cnt++;
	   }

	     void doublelist::delend()
	    {
	      i=start;
	      while(i->next!=NULL)
	      {
		 ptr=i;
		 i=i->next;
		}
	     ptr->next=NULL;
	     delete i;
	     temp =ptr;
	  //   cnt--;
	  cout<<"\n Node is deleted";
	  }

	    void doublelist::delpos()
      {
	temp=start;
	int pos=1,j=0,cnt;
	cout<<"\n Enter position:\n";
	cin>>pos;
	if(pos==1||pos==cnt)
	{
	 cout<<"Enter position more than 1 and less than last node";

	 while(temp!=NULL)
	 {
	  // int x;
	   x=temp->next;
	   temp->next=temp->next->next;
	   delete x;
	  cout<<"Node deleted";
	 }
	}
	else
	 {
	    temp=temp->next;
	    }
	      j++;
	   }
	   // cnt--;



	  void doublelist::display()
	  {
	    if(start==NULL)
	     {
	     cout<<"\n List is empty";
	    }

	    else
	     {
	       cout<<"\n List is:";
	       for(i=start;i!=NULL;i=i->next)
		{
		   cout<<" "<<i->info;
		 }
	      }
	   }


	   void main()
	   {

	    clrscr();

	    int ch;
	    cout<<"\n Program to implement opertions on doubly linkedlist\n";
	    cout<<"\n1.create node";
	    cout<<"\n2.Insert node at the beginning";
	    cout<<"\n3.Insert node at the end";
	    cout<<"\n4.Delete node at the beginning";
	    cout<<"\n5.Delete node at the specified position";
	    cout<<"\n Enter your choice:";
	    cin>>ch;

	    while(ch!=0)
	    {
	       doublelist d;
	       switch(ch)
	       {
		  case 1:
			  d.create();
			  break;

		   case 2:
			   d.infront();
			   break;
		   case 3:
			   d.inend();
			   break;
		   case 4:
			   d.delend();
			   break;
		   case 5:
			   d.delpos();
			   break;
		  case 6:
			   exit(0);
		//	   d.display();
		 //	   break;

		 default:
			    cout<<"wrong choice";

		 }
		}

		getch();
		}







































