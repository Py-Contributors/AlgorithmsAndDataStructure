class stack(object):
    def __init__(self): 
        self.items = []

    def isEmpty(self):
        return len(self.items) == 0

    def length(self):
        return len(self.items)
    
    def push(self, element):
        self.items.append(element)

    def top(self, element, underflow):
        if self.isEmpty():
            underflow = True
        else:
            underflow = False
            element = self.items[len(self.items) - 1]
        return element, underflow

    def pop(self, element, underflow):
        if isEmpty():
            underflow = True
        else:
            underflow = False
            element = self.items.pop()
        return element, underflow

    def display(self):
        for i in range(len(self.items)):
            print(self.items[i])