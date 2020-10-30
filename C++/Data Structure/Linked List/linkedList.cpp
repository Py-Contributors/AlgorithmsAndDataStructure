/*
    * Linked List implentation in C++    
*/
#include <iostream>
using namespace std;

struct node {

    int data;
    node *next;
};

class Linked_list {

    private:
        node *head, *tail;
    public:
        Linked_list() {

            head = NULL;
            tail = NULL;
        }
    
    void insert(int n) {
        node * tmp = new node;
        tmp -> data = n;
        tmp -> next = NULL;

        if(head == NULL) {
            
            head = tmp;
            tail = tmp;
        }else{

            tail->next =tmp;
            tail = tail->next;
        }
    }

// Insert at given Position
    void insertatposition(int n,int pos){
         node * tmp=new node;
         node * p;
         p= head;
         tmp -> data = n;
         tmp -> next = NULL;

         for(int i=1;i<pos-1;i++)
            p=p->next;
        tmp->next=p->next;
        p->next=tmp;
   
    };
// Delete at given Position
    void deleteatposition(int pos){
        node *p;
        int i,count=0;
        p=head;
        if(pos==1){
            head=head->next;
            free(p);
            return;
        }

        for(i=1;i<pos-1;i++)
           p=p->next;

        
        if(p->next==NULL)
          p->next->next=NULL;
        else
          p->next=p->next->next;
}

    void display() {
        node *tmp;
        tmp = head;
        while(tmp != NULL) {
            cout << tmp -> data << " ";
            tmp = tmp -> next;
        }
    }
};

int main() {
    
    Linked_list a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    cout << "The linked list is: " << endl;
    a.display();
    cout << "\nThe linked list After Inserting 42 at position 2: " << endl;
    a.insertatposition(42,2);
    a.display();
    cout << "\nThe linked list After Deleting 42 at position 2: " << endl;
    a.deleteatposition(2);
    a.display();
    return 0;
}
