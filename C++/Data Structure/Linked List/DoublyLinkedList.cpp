#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* previous;
    Node* next;

    // constructor
    Node(int data)
    {
        this -> data = data;
        this -> previous = NULL;
        this -> next = NULL;
    }

    ~Node()
    {
        int value = this -> data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for Node data " << value << endl;
    }

};

// printing
    void print(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " " ;
            temp = temp -> next;
        }
        cout << endl;
    }

// counting length
    int length(Node* head)
    {
        Node* temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp -> next;
        }
        return count;    
    }

// insert at head
    void insertAtHead(Node* &head, Node* &tail, int data)
    {
        if(head == NULL)
        {
            // to skip null point exception we will make an new node if the head which is passed is pointing to null
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        }
        else
        {

        Node* temp = new Node(data);

        // temp next address positon now points to head
        temp -> next = head;
        // head previous points to temp;
        head -> previous = temp;
        head = temp;

        }
    }

// inserting at tail
    void insertAtTail(Node* &tail,Node* &head, int data)
    {
        if(tail == NULL)
        {
            Node* temp = new Node(data);
            tail = temp;
            head = temp;
        }
        else
        {
            Node* temp = new Node(data);
            tail -> next = temp;
            temp -> previous = tail;
            tail = temp;
        }
    }

// insertingAtPosition
    void insertAtPosition(Node* &tail, Node* &head, int position ,int data)
    {
        // insert at head
        if(position == 1)
        {
            insertAtHead(head,tail,data);
            return ;
        }

        Node* temp = head;
        int count = 0;
        while(count != position-1)
        {
            temp = temp -> next;
            count++;
        }

        // insert at tail
        if(temp -> next == NULL)
        {
            insertAtTail(tail,head,data);
            return ;
        }

        // inserting at position
//      video link https://youtu.be/q8gdBn9RPeI?t=4561
        Node* nodeToInsert = new Node(data);
        nodeToInsert -> next = temp -> next;
        temp -> next -> previous = nodeToInsert;
        temp -> next = nodeToInsert;
        nodeToInsert -> previous = temp;
    }


    // deletion or making the memory free
    void deletion(Node* &head,int position)
    {
        if(position == 1)
        {
            Node* temp = head;
            head = temp -> next;
            temp -> next -> previous = NULL;
            temp -> next = NULL;
            delete temp;
        }
        else
        {
            Node* current = head;
            Node* previous = NULL;

            int count = 1;
            while (count < position)
            {
                previous = current;
                current = current -> next;
                count++;
            }
                current -> previous = NULL;
                previous -> next = current -> next;
                previous -> next = NULL;
                delete current;
            
        }
    }



int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    int getlength = length(head);
    cout << "Length of linked list is " << getlength << endl;
    
    insertAtHead(head,tail,19);
    print(head);

    insertAtHead(head,tail,18);
    print(head);

    insertAtHead(head,tail,16);
    print(head);

    insertAtTail(tail,head,24);
    print(head);

    insertAtPosition(tail,head,4,23);
    print(head);
    deletion(head,1);
    print(head);
    return 0;
}
