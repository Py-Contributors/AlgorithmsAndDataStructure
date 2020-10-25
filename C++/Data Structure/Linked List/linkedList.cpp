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
        unsigned int size;
    public:
        Linked_list() {

            head = NULL;
            tail = NULL;
            size = 0;
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
        size++;
    }

    bool insertAt(unsigned int index, int value){
        if(index > size)
            return false;
        
        size++;
        // Insert at the end of the list
        if(index == size){
            insert(value);
            return true;
        }
        
        node * tmp = new node;
        tmp -> data = value;
        tmp -> next = NULL;
        
        // Insert at the begining of the list
        if(index == 0){
            tmp -> next = head;
            head = tmp;
            return true; 
        }

        // Insert in between list
        unsigned int current_index = 0;
        node *temp = head;
        while(temp){
            if(current_index == index - 1){        
                tmp -> next = temp->next;
                temp->next = tmp;
            } 
            temp = temp->next;
            current_index++;
        }
        return true;
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

    a.insertAt(1, 5);
    cout<< "\nThe linked list after insertAt(2,5)"<<endl;
    a.display();
    return 0;
}