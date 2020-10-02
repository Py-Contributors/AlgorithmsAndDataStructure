// stack implementation using linkedlist from scratch

#include<bits/stdc++.h>
using namespace std;

// linkedList class for stack
class stackNode{
    // data and pointer part of node
    int data;
    stackNode *next;
    public:
        // constructor to create new node
        stackNode *newNode(int data){
            stackNode *temp = new stackNode();
            temp->data = data;
            temp->next = NULL;
        }
        // function to push node
        void push(stackNode **root, int data){
            stackNode *node = newNode(data);
            node->next = (*root);
            (*root) = node;
            cout << data << " pushed to stack\n";
        }
        // function to check if list is empty or not
        int isEmpty(stackNode *root) {return !root;}
        // function to pop elements from stack
        int pop(stackNode **root){
            if(isEmpty(*root))
                return INT_MIN;
            stackNode *temp = *root;
            *root = (*root) -> next;
            int popped = temp->data;
            delete temp;
            return popped;
        }
        // function to look at the top of the stack
        int peek(stackNode *root){
            if(isEmpty(root))
                return INT_MIN;
            return root->data;
        }
};

/*

INPUT
10 20 30 (to stack)

OUTPUT
10 pushed to stack
20 pushed to stack
30 pushed to stack
30 popped from stack
20 top of stack

Time Complexity O(n)
Space Complexity O(n)

*/
int main(){
    // creating root node
    stackNode *root = NULL;
    root->push(&root, 10);
    root->push(&root, 20);
    root->push(&root, 30);
    
    cout << root->pop(&root) << " popped from stack\n";
    cout << root->peek(root) << " top of stack\n";

    return 0;
}
