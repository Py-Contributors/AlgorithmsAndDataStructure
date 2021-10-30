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

    unsigned int count() const {
        return size;
    }
    
    bool insertAt(unsigned int index, int value) {
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
                tmp -> next = temp -> next;
                temp -> next = tmp;
                return true;;
            } 
            temp = temp -> next;
            current_index++;
        }
        return true;
    }

    bool remove(unsigned int index) {
        if(index >= size){
            return false;
        }    
        node * prev = NULL;
        node * curr = head;
        unsigned int curr_index = 0;
        while(curr){
            if(curr_index == index){
                if(prev == NULL){
                    head = head -> next;
                }
                else {
                    prev -> next = curr -> next;
                }
                delete curr;
                curr = NULL;
                size--;
                return true;
            }
            prev = curr;
            curr = curr->next;
            curr_index++;
        }
        return false;
    }

    void display() {
        node *tmp;
        tmp = head;
        while(tmp != NULL) {
            cout << tmp -> data << " ";
            tmp = tmp -> next;
        }
    }

    void clear(){
        while(head){
            node * curr = head;
            head = head -> next;
            delete curr;
            curr = NULL;
            --size;
        }
        head = NULL;
    }

    void reverse()
    {
        node *aux, *current=head, *previous=NULL;

        while(current!=NULL)
        {
            aux=current->next;
            current->next=previous;
            previous=current;
            current=aux;
        }
        aux=tail;
        tail=head;
        head=aux;
    }

    ~Linked_list(){
        // This is a destructor for Linked list class.
        // This will be called when a stack allocated object of this class will go out of scope.
        // Or when a heap allocated object of this class is deleted.
        // This will release all allocated memory.
        clear();
    }
};

int main() {
    
    Linked_list list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    
    cout << "\nThe linked list is: " << endl;
    list.display();
    cout << "\nSize of the list: " << list.count();

    cout << "\nThe linked list after reverse() is: " << endl;
    list.reverse();
    list.display();
    list.reverse();

    list.insertAt(1, 5);
    cout<< "\nThe linked list after insertAt(2,5)" << endl;
    list.display();
    cout << "\nSize of the list: " << list.count();

    list.remove(1);
    cout<< "\nThe linked list after remove(1)" << endl;
    list.display();
    cout << "\nSize of the list: " << list.count();

    list.clear();
    cout << "\nSize of the list after clear(): " << list.count() << endl;
    
    return 0;
}