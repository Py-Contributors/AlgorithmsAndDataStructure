#include<iostream>          //including required header files
#include<stdlib.h>    
using namespace std;

class treenode               //class treenode to create tree
{
 public:
 int data;
 treenode *left,*right;
};

class tree               //class tree
{
 public:
 
 void loop(treenode *head,treenode *root)      //traverse tree while entering data
 {
  int a;
  for(;;)
  {
   cout<<"\nWhich side do you want to go(1->Left/2->Right/3->Enter data/4->leave tree) : ";
   cin>>a;
   
   if(a==1)
   head=head->right;
    
   else if(a==2)
   head=head->left;
   
   else if(a==3)
   {
    cout<<"\nEnter data(1->left/2->right) : ";
    cin>>a;
    
    if(a==1)
    pushl(head);
    
    else if(a==2)
    pushr(head);
   }
   
   else if(a==4)
   break;
   
   else
   cout<<"\nWRONG CHOICE ENTER AGAIN\n";
   
   head=root;
  }
 }
  
 treenode* pushr(treenode *head)        //pushr function to push data to right of tree
 {
  treenode *temp=new treenode;
  cout<<"Enter data : ";
  cin>>temp->data;
  head->right=temp;
  head=head->right;
  temp->right=NULL;
  
  return head;
 }
 
 treenode* pushl(treenode *head)        //pushl function to push data to left of tree
 {

  treenode *temp=new treenode;
  cout<<"Enter data : ";
  cin>>temp->data;
  head->left=temp;
  head=head->left;
  temp->left=NULL;
  
  return head;
 }
 
 void preorder(treenode *root)     //preorder tree traversal
 {
  if(root!=NULL)
  {
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
  }
 }
 
 void postorder(treenode *root)     //postorder tree traversal
 {
  if(root!=NULL)
  {
   preorder(root->left);
   preorder(root->right);
   cout<<root->data<<" ";
  }
 }
 
 void inorder(treenode *root)      //inorder tree traversal
 {
  if(root!=NULL)
  {
   preorder(root->left);
   cout<<root->data<<" ";
   preorder(root->right);
  }
 }
 
 void leaf(treenode *root)        //function to display leaf node of tree
 {
  if(root!=NULL)
  {
   if(root->left==NULL && root->right==NULL)
   cout<<root->data<<",";
   
   leaf(root->left);
   leaf(root->right);
  }
 }
 
 int depth(treenode *root)      //function to get depth of tree
 {
  if(root==NULL)
  return 0;
  
  return(1+max(depth(root->left),depth(root->right)));
 }
 
 treenode *copy(treenode *root)  //function to copy tree
 {
  treenode *temp=new treenode;
  if(root!=NULL)
  {
   temp->left=NULL;
   temp->right=NULL;
   temp=root;
  }
  
  if(root->left!=NULL)
  temp->left=copy(root->left);
    
  if(root->right!=NULL)
  temp->right=copy(root->right);
 
  return temp;
 }
 
 void cpytree(treenode *root)     //main function to copy tree
 {
  root=copy(root);
  cout<<"\nTree copied\n";
 }
};

int main()               //main function
{
 tree obj;              //object of class tree

 treenode *head=new treenode;
 cout<<"Enter root node : ";       //enter root node
 cin>>head->data;
 
 treenode *root=new treenode;
 root=head;
 
 int ch,dep;
 
 for(;;)                    //menu
 {
  cout<<"\n\nMENU\n1)Enter Data\n2)Display\n3)Leaf nodes\n4)Depth\n5)Copy tree\n6)Exit\nEnter your choice : ";
  cin>>ch;
 
  switch(ch)
  {
    case 1:obj.loop(head,root);
           break;
           
    case 2:for(;ch!=4;)
           {
            cout<<"\n\n1)Pre Order\n2)In Order\n3)Post Order\n4)Exit from display\nEnter your choice : ";
            cin>>ch;
            switch(ch)
            {
             case 1:cout<<"Displaying in preorder:\n";
                    obj.preorder(root);
                    break;
                    
             case 2:cout<<"Displaying in postorder:\n";
                    obj.postorder(root);
                    break;
                    
             case 3:cout<<"Displaying in inorder:\n";
                    obj.inorder(root);
                    break;  
            }
           }
           break;
          
    case 3:cout<<"\n\n";
           obj.leaf(root);
           break;
           
    case 4:cout<<"\n\n";
           dep=obj.depth(root)-1;
           cout<<"Depth of the tree is = "<<dep;
           break;
           
    case 5:cout<<"\n";
           obj.cpytree(root);
           break;
           
           
    case 6:exit(0);
  }
 }
 return 0;              //end of function
}





/*OUTPUT:

Enter root node : 1


MENU
1)Enter Data
2)Display
3)Leaf nodes
4)Depth
5)Copy tree
6)Exit
Enter your choice : 1

Which side do you want to go(1->Left/2->Right/3->Enter data/4->leave tree) : 1

Which side do you want to go(1->Left/2->Right/3->Enter data/4->leave tree) : 3

Enter data(1->left/2->right) : 1
Enter data : 2

Which side do you want to go(1->Left/2->Right/3->Enter data/4->leave tree) : 2

Which side do you want to go(1->Left/2->Right/3->Enter data/4->leave tree) : 3

Enter data(1->left/2->right) : 2
Enter data : 3

Which side do you want to go(1->Left/2->Right/3->Enter data/4->leave tree) : 4


MENU
1)Enter Data
2)Display
3)Leaf nodes
4)Depth
5)Copy tree
6)Exit
Enter your choice : 2


1)Pre Order
2)In Order
3)Post Order
4)Exit from display
Enter your choice : 1
Displaying in preorder:
1 2 3 

1)Pre Order
2)In Order
3)Post Order
4)Exit from display
Enter your choice : 2
Displaying in postorder:
2 3 1 

1)Pre Order
2)In Order
3)Post Order
4)Exit from display
Enter your choice : 3
Displaying in inorder:
2 1 3 

1)Pre Order
2)In Order
3)Post Order
4)Exit from display
Enter your choice : 4


MENU
1)Enter Data
2)Display
3)Leaf nodes
4)Depth
5)Copy tree
6)Exit
Enter your choice : 3


2,3,

MENU
1)Enter Data
2)Display
3)Leaf nodes
4)Depth
5)Copy tree
6)Exit
Enter your choice : 4


Depth of the tree is = 1

MENU
1)Enter Data
2)Display
3)Leaf nodes
4)Depth
5)Copy tree
6)Exit
Enter your choice : 5

Tree copied



MENU
1)Enter Data
2)Display
3)Leaf nodes
4)Depth
5)Copy tree
6)Exit
Enter your choice : 6    */

