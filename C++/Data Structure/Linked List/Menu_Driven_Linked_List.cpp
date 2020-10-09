#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;

#define fio ios::sync_with_stdio(false); cin.tie(0)
#define mp make_pair
#define minp(v) *min_element(v.begin(), v.end())
#define maxp(v) *max_element(v.begin(), v.end())
#define F first 
#define S second 
#define rep(i,a,b) for(int i=0; i<(b); ++i)
#define repe(i,a,b) for(int i=1; i<(b); ++i)

typedef long long ll;
/*
*******************************************************************************
SINGLY LINKED LIST ADT IMPLEMENTATION                 ^.^.^.^.^.^.^.^.^.^.^.^.^
^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^ ^. By:- NAMAN JAIN
*******************************************************************************
*/
struct Node
{
  int data;
  Node *next,*prev;
};
int val, wall;

Node *create_node(int x){
  Node *new_node = new Node;
  new_node->data = x;
  new_node->next = new_node;
  new_node->prev = new_node;
  return new_node;
}
void insert_beg(Node **head, int data){
  if(head == NULL){
    *head = create_node(data);
  }else{
    Node *temp = new Node;
    temp->data = data;
    temp->prev = (*head)->next;
    temp->next = (*head)->prev;
     // the parentheses around *head are needed because the precedence of * is lower than ->
    *head = temp;
  }
}
// Append new node to list
void insert_end(Node **head, int data){
  if(head == NULL){
    (*head) = create_node(data);
    return;
  }
  Node *temp = *head;
  while(temp->next!= (*head)){
    temp = temp->next;
  }
  Node* new_node = create_node(data);
  new_node->next = (*head);
  new_node->prev = temp;
  (*head)->prev     = new_node;
  temp->next     = new_node; 
}
// Insert before first occurence of passed value
void insert_before(Node *head, int data, int wall){
  if(head==NULL)  return;
  Node *temp = new Node;
  temp = head;
  if(head->data == wall)
  {
    insert_beg(&head, data);
  }
  while(temp->next->data != wall){
    temp = temp->next;
  }
  Node* ptr = create_node(data);
  ptr->next        = temp->next;
  temp->next->prev = ptr;
  ptr->prev        = temp;
  temp->next       = ptr;  
}
// Delete head node
int del_beg(Node **head){
  Node *temp = *head;
  if(temp == NULL){
    cout<<"List is Empty"<<endl;
    return -1;
  } 
  (*head)->next->prev = (*head)->prev;
  (*head) = (*head)->next;
  // temp->next->prev = (*head)->prev;
  (*head) = temp->next;
  int x  = temp->data;
  delete temp;
  // (*head) = (*head)->next;
  return x;
}
// Delete end node
int del_end(Node **head){
  if(*head == NULL){
    cout<< "\nEmpty List\n";
    return -1;
  }
  Node *prev,*temp = *head;
  while (temp->next != (*head))
  {
    prev = temp;
    temp = temp->next;
  }
  int x ;
  prev->next=(*head);
  (*head)->prev=prev;
  x = temp->data;
  delete temp;
  return x;
}

// Delete all occurence of passed value
void del_val(Node **head, int val){
  if(*head == NULL){
    cout<< "\nEmpty List\n";
    return;
  }
  Node *prev,*temp = *head;
  while (temp->next != *head && temp->data != val) 
  {   
    prev = temp; 
    temp = temp->next; 
  }
  if(temp->data != val){
    cout<<"Not found";
  }else if(temp == (*head)){
    del_beg(&temp);
  }else{
    prev->next = temp->next;
    delete temp;
  }
}

int search_val(Node *head, int val){
  int pos = 0;
  if(head == NULL){
    cout<< "\nEmpty List\n";
    return pos;
  }
  Node *temp = head;
  while(temp!= NULL && temp->data!=val){
    temp = temp->next;
    pos+=1;
  }
  return pos+1;
}

// Display Linked List
void display(Node *head){
  Node *temp = new Node;
  temp = head;
  if(head == NULL){
    cout<<"List is Empty\n";
  }
  while(temp!= NULL){
    cout << temp->data<<' ';
    temp = temp->next;
  }
  cout<<"\n";
}
void menuItems()
{
 // Using Raw String Literal 
  cout<<R"(
1. INSERT at Beginning
2. INSERT at End
3. INSERT Before Passed Value
4. DELETE from Beginning
5. DELETE from End
6. DELETE Passed Value
7. SEARCH by Value and Get it's Position
8. DISPLAY
9. EXIT
)";
}

int main()
{
  // fio;
  menuItems();
  int choice;
  Node *root = NULL;

  do{
    cout<<"Enter your choice:";
    cin>>choice;
    switch (choice)
    {
    case 1:
      cout<<"Enter value to be inserted at beginning:=";
      cin>>val;
      insert_beg(&root, val);
      break;
    case 2:
      cout<<"Enter value to be inserted at end:=";
      cin>>val;
      insert_end(&root, val);
      break;
    case 3:
      cout<<"Enter value to be inserted and before what value:=";
      cin>>val>>wall;
      insert_before(root, val, wall);
      break;
    case 4:
      val = del_beg(&root);
      cout<<val<<"\n";
      break;
    case 5:
      val = del_end(&root);
      cout<<val<<"\n";
      break;
    case 6:
      cout<<"Enter value to be deleted:=";
      cin>>val;
      del_val(&root, val);
      break;
    case 7:{
     cout<<"Enter value to be searched: ";
    cin>>val;
    int test = search_val(root, val) ;
    if(test < 0)
      cout<<"Element not present";
    else
        cout<<"Element found at "<<test<<endl;
      break;}
    case 8:
      display(root);
      break;
    default:
      exit(0);
    }
  }while(true);
} 