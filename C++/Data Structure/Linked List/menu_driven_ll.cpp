/*This is a menu driven program for a singly linked list*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *next;
};

struct node* new_node(int key) 
{ 
    struct node *temp = new node(); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

void print_menu()
{
  cout<<"----------MENU------------";
  cout<<"\n1. Insert a node into the linked list at the beginning.";
  cout<<"\n2. Delete a node from the linked list.";
  cout<<"\n3. Display the linked list.";
  cout<<"\n4. Search for a node in the linked list";
  cout<<"\n5. Delete a node at the beginning of the linked list";
  cout<<"\nEnter your choice : ";
}

node* add(node* head, int num)
{
  node *t = new_node(num);
  if(head==NULL)	//If the linked list is empty
  head = t;
  else			//IF one or more nodes already exist.
  {
    t->next = head;
    head = t;
  }
  return head;
}

void display(node* head)
{
  node *t = head;
  cout<<"The linked list is as follows -\n";
  while(t)
  {
    cout<<t->data<<" -> ";
    t=t->next;
  }
  cout<<"NULL\n";
}

void search(node* head, int num)
{
  node *t = head;
  int loc =1;
  bool found = false;
  while(t)
  {
    if(t->data == num)
    {
      found = true;
      break;
    }
    loc++;
    t = t->next;
  }
  if(found)
  cout<<num<<" found at location "<<loc<<endl;
  else
  cout<<num<<" not found\n";
}

node* del1(node* head, int num)
{
  node *prev, *cur;
  bool is_present = false;
  prev = NULL;
  cur = head;
  while(cur)
  {
    if(cur->data==num)
    {
      prev->next = cur->next;
      cur->next = NULL;
      delete cur;
      is_present = true;
      break;
    }
    prev = cur;
    cur = cur->next;
  }
  if(!is_present)
  cout<<num<<" not found\n";
  else
  cout<<"Deletion Completed\n";
  return head;
}

node* del2(node* head)
{
  node* t = head;
  head = head->next;
  t->next = NULL;
  cout<<"Deletion Completed\n";
  delete t;  
  return head;
}

int main()
{
  int n,num;
  node *head = NULL;
  int continued = 1;
  while(continued)
  {
    print_menu();
    cin>>n;
    switch(n)
    {
      case 1: cout<<"Enter the data : ";
      	      cin>>num;
      	      head = add(head,num);
      	      break;
      case 2: cout<<"Enter the data : ";
      	      cin>>num;
      	      head = del1(head,num);
      	      break;
      case 3: display(head);
      	      break;
      case 4: cout<<"Enter the data : ";
      	      cin>>num;
      	      search(head,num);
      	      break;
      case 5: head = del2(head);
      	      break;
    }
    cout<<"\nDo you wish to continue? 0 -> no	1->yes ";
    cin>>continued; 
  }
  return 0;
}
