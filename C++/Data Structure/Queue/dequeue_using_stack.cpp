#include<bits/stdc++.h>
using namespace std;
stack<int>s1,s2;

void Enqueue(int n)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(n);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

void Dequeue()
{
    cout<<s1.top()<<endl;
    s1.pop();
}

int main()
{
    int n,i;
    cout<<"Enter the number digits to be added in queue : "<<endl;
    cin>>n;
    cout<<"Enter the digits : "<<endl;
    for(i=0;i<n;i++)
    {
        int num;
        cin>>num;
        Enqueue(num);
    }
    while(1)
    {
    cout<<"Press 1 to dequeue "<<endl;
    cin>>i;
    if(i==1)
    {
        Dequeue();
    }
    else{
        return 0;
    }
    }
}
