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