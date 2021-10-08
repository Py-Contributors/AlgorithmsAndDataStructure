
#include<bits/stdc++.h>
#include<queue>
using namespace std;
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    if(q1.empty()&&q2.empty())
    q1.push(x);
    else if(q1.empty())
    q2.push(x);
    else
    q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()&&q2.empty())
    return -1;
    else if(q2.empty())
    {
        while(q1.size()!=1)
        { 
           q2.push(q1.front());
           q1.pop();
    }
    int y=q1.front();
    q1.pop();
    return y;
    }
    else
    {
         while(q2.size()!=1)
        { 
           q1.push(q2.front());
           q2.pop();
    }
    int y=q2.front();
    q2.pop();
    return y;
    }
}
int main() 
{
  QueueStack q;
  q.push(5);
  q.push(6);
  cout<< q.pop();  // LIFO
}
