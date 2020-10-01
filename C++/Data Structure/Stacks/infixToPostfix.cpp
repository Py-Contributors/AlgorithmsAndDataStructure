#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct stack{
	int top;
	char items[SIZE];
};

void push(struct stack *ps, char symb){
	if(ps->top>=SIZE-1){
		printf("Stack Overflow");
		exit(1);
	}
	else
		ps->items[++ps->top] = symb;
}

int empty(struct stack *ps){
	if(ps->top==-1)
		return 1;
	else
		return 0;
}

char pop(struct stack *ps){
	if(empty(ps)){
		printf("Stack Underflow");
		exit(1);
	}
	return ps->items[ps->top--];
}

char stacktop(struct stack *ps){
	if(empty(ps)){
		printf("Stack is empty");
	}
	else
		return ps->items[ps->top];
}

int main(){
	
	char *convert(char*);
	
	char infix[SIZE];
	int pos=0;
	
	while((infix[pos++]=getchar())!='\n');
	infix[--pos]='\0';
	
	
	printf("%s",convert(infix));
	
	return 0;
}

char * convert(char *infix){
	
	int prcd(char,char);
	int isOpnd(char);
	int isOper(char);
	
	struct stack opstk;
	opstk.top=-1;
	struct stack postfix;
	postfix.top=-1;
	
	char symb;
	
	for(int i=0;(symb=infix[i])!='\0';i++){
		if(isOpnd(symb)){
			push(&postfix,symb);
		}
		else if(isOper(symb)){
			while((!empty(&opstk))&&prcd(stacktop(&opstk),symb)){
				push(&postfix,pop(&opstk));
			}
			push(&opstk,symb);

		}
		else if(symb==')'){
			while(stacktop(&opstk)!='('){
				push(&postfix,pop(&opstk));
			}
			pop(&opstk);
		}
		else{
			printf("Illegal Symbol");
		}
	}
	
	while(!empty(&opstk)){
		push(&postfix,pop(&opstk));
	}
	
	int c;
	char converted[SIZE];	
	for(int i=0;i<=postfix.top;i++){
		converted[i]=postfix.items[i];
	}

	return converted;
}

int isOpnd(char symb){
	return (symb>='0'&&symb<='9')||(symb>='a'&&symb<='z')||(symb>='A'&&symb<='Z');
}

int isOper(char symb){
	return symb=='+'||symb=='*'||symb=='/'||symb=='-'||symb=='$'||symb=='(';
}

int prcd(char op1,char op2){
	if(op1=='('){
		return 0;
	}
	
	if(op1=='+'){
		if(op2=='*'||op2=='/'||op2=='$'||op2=='(')
			return 0;
		else
			return 1;
	}
	else if(op1=='-'){
		if(op2=='*'||op2=='/'||op2=='$'||op2=='(')
			return 0;
		else
			return 1;
	}
	else if(op1=='*'){
		if(op2=='$'||op2=='(')
			return 0;
		else
			return 1;
	}
	else if(op1=='/'){
		if(op2=='$'||op2=='(')
			return 0;
		else
			return 1;
	}
	else if(op1=='$'){
		if(op2=='$'||op2=='(')
			return 0;
		else
			return 1;
	}
}







