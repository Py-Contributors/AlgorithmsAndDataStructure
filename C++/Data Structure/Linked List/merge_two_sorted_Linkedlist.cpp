// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node *mhead=NULL;
    Node *mtail=NULL;
    while(head1 !=NULL && head2 != NULL){
        if(mhead==NULL){
            
            if(head1->data < head2->data){
                mhead=head1;
                mtail=head1;
                head1=head1->next;
            }

            else{
                mhead=head2;
                mtail=head2;
                head2=head2->next;
            }
        }

        else{
            if(head1->data < head2->data){
                mtail->next=head1;
                mtail=head1;
                head1=head1->next;
            }
            else{
                mtail->next=head2;
                mtail=head2;
                head2=head2->next;
            }
        }

    }  //while loop

    while(head1 == NULL && head2 != NULL) {
        mtail->next=head2;
        mtail=head2;
        head2=head2->next;
    }

    while(head2 == NULL && head1 != NULL) {
        mtail->next=head1;
        mtail=head1;
        head1=head1->next;
    }

    return mhead;
}