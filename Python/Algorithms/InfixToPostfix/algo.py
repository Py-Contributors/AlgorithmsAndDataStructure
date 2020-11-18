class node:
    def __init__(self,data=None,next=None):
        self.data=data
        self.next=next

class Stack:
    def __init__(self):
        self.start=None
        self.pushOnTop('(')

    def pushOnTop(self,data):
        p=node(data,None)
        if self.start==None:
            self.start=p
            return
        else:
            p.next=self.start
            self.start=p

    def pop(self):
        temp=self.start.data
        self.start=self.start.next
        return temp

    def peek(self):
        if self.start==None:
            print("Stack is Empty")
        else:return (self.start.data)

    def display(self):
        q=self.start
        while(q):
            print(q.data,end=" ")
            q=q.next
        print("Left side is Top")

newStack = Stack()
data=[]
string = input("Enter the String: ")+')'
for i in string:
    if i in ['+','-','*','/','^']:
        if i in ['+','-']:
            while True:
                if newStack.peek() in ['*','/','^','+','-']:
                    print('aaaak')
                    data.append(newStack.pop())
                else:
                    print('bbbk')
                    break
            newStack.pushOnTop(i)
        elif i in ['*','/']:
            while True:
                if newStack.peek() in ['*','/','^']:
                    data.append(newStack.pop())
                else:
                    break
            newStack.pushOnTop(i)
        else:
            while True:
                if newStack.peek() == '^':
                    data.append(newStack.pop())
            newStack.pushOnTop('^')
    elif i==')':
        while True:
            if newStack.peek() == '(':
                newStack.pop()
                break
            else:
                data.append(newStack.pop())
    elif i=='(':
        newStack.pushOnTop('(')
    else:
        data.append(i)
for i in data: print(i,end=" ")
#   a+(b*c-(d/e^f)*g)*h