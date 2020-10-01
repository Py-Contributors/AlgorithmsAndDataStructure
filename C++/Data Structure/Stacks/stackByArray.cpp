// I/O header file
#include<iostream>
using namespace std;

#define MAX 1000

// creating stack class 
class Stack{
    int top;
    public:
        // declaration of array
        int a[MAX];
        // constructor of array, top = -1 because of empty Stack
        Stack(){top = -1;}
        bool push(int x);
        int pop();
        int peek();
        bool isempty();
};

// class fucntions definations
bool Stack::push(int x){
    // condition to check if stack is full or not
    if(top >= (MAX - 1)){
        cout << "Stack is Overflow\n";
        return false;
    }
    else{
        a[++top] = x;
        cout << x << " pushed into Stack\n";
        return true;
    }
}

// remove top of stack
int Stack::pop(){
    // condition to check if stack is empty
    if(top < 0){
        cout << "Stack Underflow\n";
        return 0;
    }
    else{
        int x = a[top--];
        return x;
    }
}

// getting top of stack
int Stack::peek(){
    // condition for empty Stack
    if(top < 0){
        cout << "Stack Underflow\n";
        return 0;
    }
    else{
        int x = a[top];
        return x;
    }
}

// check for empty stack
bool Stack::isempty(){
    return (top < 0);
}


/*

INPUT
10 20 30 (to stack)

OUTPUT
10 pushed into Stack
20 pushed into Stack
30 pushed into Stack
30 Popped from Stack
20
0

Time Complexity O(n)
Space Complexity O(n)

*/

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from Stack\n";
    cout << s.peek() << endl;
    cout << s.isempty() << endl;


    return 0;
}