/* A queue can be implemented using two stacks in two ways.
      1. By making enqueue operation costly
      2. By making dequeue operation costly 
   Here we discuss the second method however the first could be implemented
   in the same way interchanging enqueue and dequeue methods. */
/* Time complexity for enqueue : O(n), for dequeue : O(1) */

#include <bits/stdc++.h>
using namespace std;
stack<int> s1, s2;

void Enqueue(int n)
{
    while (!s1.empty())
    {
        s2.push(s1.top()); //push all elements from s1 to s2
        s1.pop();
    }
    s1.push(n); // push the element to be enqueue to s1
    while (!s2.empty())
    {
        s1.push(s2.top()); // push all elements from s2 to s1.
        s2.pop();
    }
}

int Dequeue()
{
    while (1)
    {
        cout << "Press 1 to dequeue ";
        int op;
        cin >> op;
        if (op == 1)
        {
            if (!s1.empty())
            {
                cout << s1.top() << endl; // remove the top element
                s1.pop();
            }
            else
            {
                cout << "No element to dequeue";
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int n, i;
    cout << "Enter the number digits to be added in queue : " << endl;
    cin >> n;
    cout << "Enter the digits : " << endl;
    for (i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        Enqueue(num);
    }
    Dequeue();
}
