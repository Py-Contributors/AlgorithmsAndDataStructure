# Implement Stack in python

class stack:
    
    # Function to initialize stack
    # Time Complexity : O(1)
    def __init__(self):
        self.ls = []

    # Function to push an element
    # Time Complexity : O(1)
    def push(self, x):
        self.ls.append(x)
    
    # Function to pop 
    # Time Complexity : O(1)
    def pop(self):
        if(len(self.ls)>0):
            return self.ls.pop()
        else:
            return -1 # when stack is empty
        
    # Function to return the top
    # Time Complexity : O(1)
    def top(self):
        if(len(self.ls)>0):
            return self.ls[len(self.ls)-1]
        else:
            return -1 # when stack is empty

s = stack() #LIFO 
s.push(2)
s.push(3)
s.push(1)
s.push(5)
s.push(7) 
print(s.top()) # 7
s.pop()
s.pop()
print(s.top()) # 1
