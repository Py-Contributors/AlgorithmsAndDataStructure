/* Queue is a data structure with FIFO (first in first out) arrangement */
/* The elements in the queue are inserted at the back and deleted from the front */

#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> q) // for printing the elements
{
    while (!q.empty()) // While the queue is not empty we print the front element by removing the elements
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q; // Queue of type int
    while (1)
    {
        cout << "Press 1 to enqueue\n2 to dequeue \n3 to print\n0 to exit" << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "Enter the element to be pushed" << endl;
            int num;
            cin >> num;
            q.push(num); // push() is used to push the elements at the back of the queue
        }
        if (n == 2)
        {
            q.pop(); // pop removes the front element from the queue
        }
        if (n == 3)
        {
            printQueue(q);
        }
        if (n == 0)
        {
            return 0;
        }
    }
}
