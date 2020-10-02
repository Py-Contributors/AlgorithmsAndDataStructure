// CPP program to evaluate value of a postfix 
// expression having multiple digit operands 
#include <bits/stdc++.h> 
using namespace std; 

// Stack type 
class Stack 
{ 
	public: 
	int top; 
	unsigned capacity; 
	int* array; 
}; 

// Stack Operations 
Stack* createStack( unsigned capacity ) 
{ 
	Stack* stack = new Stack(); 

	if (!stack) return NULL; 

	stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = new int[(stack->capacity * sizeof(int))]; 

	if (!stack->array) return NULL; 

	return stack; 
} 

int isEmpty(Stack* stack) 
{ 
	return stack->top == -1 ; 
} 

int peek(Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

int pop(Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(Stack* stack,int op) 
{ 
	stack->array[++stack->top] = op; 
} 


// The main function that returns value 
// of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
	// Create a stack of capacity equal to expression size 
	Stack* stack = createStack(strlen(exp)); 
	int i; 

	// See if stack was created successfully 
	if (!stack) return -1; 

	// Scan all characters one by one 
	for (i = 0; exp[i]; ++i) 
	{ 
		//if the character is blank space then continue 
		if(exp[i] == ' ')continue; 
		
		// If the scanned character is an 
		// operand (number here),extract the full number 
		// Push it to the stack. 
		else if (isdigit(exp[i])) 
		{ 
			int num=0; 
			
			//extract full number 
			while(isdigit(exp[i])) 
			{ 
			num = num * 10 + (int)(exp[i] - '0'); 
				i++; 
			} 
			i--; 
			
			//push the element in the stack 
			push(stack,num); 
		} 
		
		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{ 
			int val1 = pop(stack); 
			int val2 = pop(stack); 
			
			switch (exp[i]) 
			{ 
			case '+': push(stack, val2 + val1); break; 
			case '-': push(stack, val2 - val1); break; 
			case '*': push(stack, val2 * val1); break; 
			case '/': push(stack, val2/val1); break; 
			
			} 
		} 
	} 
	return pop(stack); 
} 

// Driver code 
int main() 
{ 
	char exp[] = "100 200 + 2 / 5 * 7 +"; 
	cout << evaluatePostfix(exp) << endl; 
	return 0; 
} 
