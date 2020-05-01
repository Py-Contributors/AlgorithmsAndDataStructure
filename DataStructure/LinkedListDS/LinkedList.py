#  Date   1/5/2020.
#   __Author__   :  CodePerfectPlus
#  __Package__  :  Python 3
#  __GitHub__  : https://www.github.com/codeperfectplus
#
from .Node import Node

class LinkedList:
    def __init__(self):
        self.head = None
        self.counter = 0

    # O(N)
    def treaverse(self):
        actualNode = self.head

        while actualNode is not None:
            print(actualNode.data)
            actualNode = actualNode.nextNode

    # O(1)
    def insertStart(self,data):

        self.counter += 1

        newNode =  Node(data)

        if not self.head:
            self.head = newNode
        else:
            newNode.nextNode = self.head
            self.head = newNode

    # O(1)
    def size(self):
         return self.counter

    # O(N) LinearTime
    def insertEnd(self,data):
        if self.head is None:
            self.insertStart(data)
            return

        self.counter += 1

        newNode = Node(data)
        actualNode = self.head

        while actualNode.nextNode is not None:
            actualNode = actualNode.nextNode

        actualNode.nextNode = newNode
     # O(N)
    def remove(self,data):

        self.counter -= 1

        if self.head:
            if data == self.head.data:
                self.head = self.head.nextNode
            else:
                self.head.remove(data,self.head)