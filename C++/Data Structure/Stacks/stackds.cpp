//C++ Program to implement Stack Data Structure
#include <bits/stdc++.h>
//Setting a Max SIZE for Stack
#define SIZE 100

using namespace std;

class Stack
{
    int item[SIZE];
    int top;

public:
    Stack() //default constructor
    {
        top = -1;
    }

    bool isEmpty() //check if stack is Empty
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return true;
        }
        return false;
    }

    bool isFull()   //check if stack in Full   
    {
        if (top == SIZE - 1)
        {
            cout << "Stack is full\n";
            return true;
        }
        return false;
    }

    void push(int val)  //push elements into the stack
    {
        if (isFull())
        {
            exit(0);
        }
        top++;
        item[top] = val;
    }

    int pop()   //pop elements from the stack
    {
        int val;
        if (isEmpty())
        {
            exit(0);
        }
        val = item[top];
        top--;
        return val;
    }

    int peek()  //return element at the top of stack
    {
        int val;
        if (isEmpty())
        {
            exit(0);
        }
        val = item[top];
        return val;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}