//Problem-Tower of Hanoi
// Tower of hanoi is a problem in which we have 3 rods and n disks.
// The objective of the problem is to move the entire stack to another rod, by following the below rules:-
// 1)Only one disk can be moved at a time.
// 2)Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack 
// i.e. a disk can only be moved if it is the uppermost disk on a stack.
// 3)No disk may be placed on top of a smaller disk


#include <bits/stdc++.h> 
using namespace std; 
  
void towerOfHanoi(int n, char source,char destination, char intermediate)  
{  
    if (n == 1)  
    {  
        cout << "Move disk 1 from rod " << source <<" to rod " << destination<<endl;  
        return;  
    }  
    //Move disk from source to intermediate using destination rod
    towerOfHanoi(n - 1, source, intermediate, destination);  
    cout << "Move disk " << n << " from rod " << source <<" to rod " << destination << endl;  
    //Finally Move disk from intermediate to destination using source rod
    towerOfHanoi(n - 1, intermediate, destination, source);  
}  
  
// Driver code 
int main()  
{  
    cout<<"Enter number of disks"<<endl;
    int n ;//Number of disks
    cin>>n;
    towerOfHanoi(n, 'S', 'I', 'D'); // S,I,D represents source ,intermediate and destination rods. 
    return 0;  
}  