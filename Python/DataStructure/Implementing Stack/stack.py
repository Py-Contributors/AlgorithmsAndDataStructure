class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        if self.items == []:
            return True
        else:
            return False

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if len(self.items) != 0:
            return self.items.pop()
        else:
            print("Stack is empty")

    def peek(self):
        if len(self.items) != 0:
            return self.items[len(self.items) - 1]
        else:
            print("Stack is empty")

    def display(self):
        return (self.items)


# __main__
s = Stack()
c = 0
while c != 5:
    print('\tSTACK OPERATIONS')
    print('1.Push')
    print('2.Pop')
    print('3.Peek')
    print('4.Display Stack')
    print('5.Exit')
    c = int(input('Enter your choice(1-5): '))
    if c == 1:
        x = input("Enter the item: ")
        s.push(x)
    elif c == 2:
        s.pop()
    elif c == 3:
        s.peek()
    elif c == 4:
        print(s.display())
    elif c != 5:
        print('Wrong Choice! Choose from 1 to 5 only')

print('Bye')
