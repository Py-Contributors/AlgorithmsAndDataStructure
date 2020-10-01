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

void print(node *head)
{
  node *temp = head;
  cout<<"The linked list is as follows:\n";
  while(temp)
  {
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }
  cout<<endl;
}

node* reverse (node *head)
{
  node *cur, *prev, *next;
  cur = head;
  prev = next = NULL;
  
  while(cur)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

int main()
{
  struct node *head = new_node(10);
  head->next = new_node(20);
  head->next->next = new_node(30);
  head->next->next->next = new_node(40);
  head->next->next->next->next = new_node(50);
  
  print(head);
  head = reverse(head);
  cout<<"Linked List reversed\n";
  print(head);
  return 0; 
}
