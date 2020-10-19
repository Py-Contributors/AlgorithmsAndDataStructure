def push(lst, it):
    lst.append(it)


def Pop(lst):
    if len(lst) == 0:
        print('Stack is empty!')
    else:
        i = lst.pop()
        print("Popped item is:", i)
        global top
        top = top - 1


def peek(lst):
    if len(lst) == 0:
        print('Stack is empty!')
    else:
        global top
        print('Topmost item is:', lst[top])


def display(lst, x):
    if len(lst) == 0:
        print('Stack is empty!')
    else:
        for i in range(x, -1, -1):
            print(lst[i])


# __main__
st = []
top = None
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
        push(st, x)
        top = len(st) - 1
    elif c == 2:
        Pop(st)
    elif c == 3:
        peek(st)
    elif c == 4:
        display(st, top)
    elif c != 5:
        print('Wrong Choice! Choose from 1 to 5 only')

print('Bye')
