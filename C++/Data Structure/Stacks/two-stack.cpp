//Problem-Implement two stacks in a single array such that
// push1(int x) –> pushes x to first stack
// push2(int x) –> pushes x to second stack
// pop1() –> pops an element from first stack 
// pop2() –> pops an element from second stack 
//All operations should take O(1) time complexity


#include<bits/stdc++.h>
using namespace std;

class twoStacks { 
	int* array; 
	int size; 
	int top1, top2; 

public: 
	twoStacks(int n)  
	{ 
		size = n; 
		array = new int[n]; 
		top1 = -1; 
		top2 = size; 
	} 

	//  push an element x to stack1 in O(1) 
	void push_S1(int x) 
	{ 
		// There is at least one empty space for new element 
		if (top1 < top2 - 1) { 
			top1++; 
			array[top1] = x; 
            cout<<x<<" Pushed to stack 1\n";
		} 
        // Two tops meet, array has no space left, hence overflow
		else { 
			cout << "Overflow ! Stack full,pop elements to create space\n";  
		} 
	} 

	// push an element x to stack2 in O(1) 
	void push_S2(int x) 
	{ 
		
		if (top1 < top2 - 1) { 
			top2--; 
			array[top2] = x; 
            cout<<x<<" Pushed to stack 2\n";
		} 
		else { 
			cout << "Overflow ! Stack full, ,pop elements to create space\n";  
		} 
	} 

	// pop an element from first stack in O(1) 
	int pop_S1() 
	{ 
        //check if there is atleast 1 element
		if (top1 >= 0) { 
			int x = array[top1]; 
			top1--; 
            cout<<x<<" poped from stack 1\n";
			return x; 
		} 
        //no elements to pop
		else { 
			cout << "Underflow!\n "; 
		} 
	} 

	//  pop an element from second stack in O(1) 
	int pop_S2() 
	{ 
		if (top2 < size) { 
			int x = array[top2]; 
			top2++;
            cout<<x<<" poped from stack 2\n"; 
			return x; 
		} 
		else { 
			cout << "Underflow!\n"; 
 
		} 
	} 
}; 

/* Driver code */
int main() 
{ 
    int n;
    cout<<"Enter the capacity of the array"<<endl;
    cin>>n;
	twoStacks ts(n); 
    int i=0;
    while(1)
    {
        cout<<"Enter \n1- To push elements to stack 1\n2- To pop elements from stack 1\n3- To push elements to stack 2\n4- To pop elements from stack 2\n5- To exit\n";
        cin>>i;
        switch (i)
        {
        case 1:
            int val;
            cout<<"Enter element to be pushed\n";
            cin>>val;
            ts.push_S1(val);
            break;
        case 2:
            ts.pop_S1();
            break;
        case 3:
            cout<<"Enter element to be pushed\n";
            cin>>val;
            ts.push_S2(val);
            break;
        case 4:
            ts.pop_S2();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Enter valid number\n";
            break;
        }
    }
	
	return 0; 
} 
