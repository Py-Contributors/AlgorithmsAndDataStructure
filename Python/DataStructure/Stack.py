# Implement Stack in python

class Stack:

    '''
    Function to intialize stack
    Time Complexity : O(1)
    '''
    def __init__(self):
        self.items = []

    '''
    Function to check if the stack is empty
    Time Complexity : O(1)
    '''
    def isEmpty(self):
        return self.items == []

    '''
    Function to push an item to stack
    Time Complexity : O(1)
    '''
    def push(self, item):
        self.items.append(item)

    '''
    Function to pop an item from stack
    Time Complexity : O(1)
    '''
    def pop(self):
        return self.items.pop()

    '''
    Function to get the top of stack
    Time Complexity : O(1)
    '''
    def top(self):
        return self.items[len(self.items)-1]

    '''
    Function to find the size of stack
    Time Complexity : O(1)
    '''
    def size(self):
        return len(self.items)

s = Stack()
s.push(2)
s.push(3)
s.push(1)
s.push(4)
s.push(7)
print(s.pop())
print(s.pop())
print(s.pop())
s.pop()      
print(s.top())
