# Class to convert the expression 

class evaluate_postfix:
    
     # Constructor to initialize the class variables 
    def __init__(self):
        
        # This array is used a stack 
        self.items=[]
        self.size=-1
        
    # check if the stack is empty 
    def isEmpty(self):
        return self.items==[]
        
    # Push the element to the stack    
    def push(self,item):
        self.items.append(item)
        self.size+=1
        
    # Pop the element from the stack 
    def pop(self):
        if self.isEmpty():
            return 0
        else:
            self.size-=1
            return self.items.pop()
            
    # Return the value of the top of the stack 
    def seek(self):
        if self.isEmpty():
            return False
        else:
            return self.items[self.size]
            
    # The main function that converts given infix expression 
    # to postfix expression 
    def evalute(self,expr):
        for i in expr:
            if i in '0123456789':
                self.push(i)
            else:
                op1=self.pop()
                op2=self.pop()
                result=self.cal(op2,op1,i)
                self.push(result)
        return self.pop()
        
        
    def cal(self,op2,op1,i):
        if i is '*':
            return int(op2)*int(op1)
        elif i is '/':
            return int(op2)/int(op1)
        elif i is '+':
            return int(op2)+int(op1)
        elif i is '-':
            return int(op2)-int(op1)


s=evaluate_postfix()
expr=input('Enter the postfix expression:')
print(expr)
value=s.evalute(expr)
print('Your result',value)
