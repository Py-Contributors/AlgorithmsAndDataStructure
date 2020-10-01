#  Date   1/5/2020.
#   __Author__   :  CodePerfectPlus
#  __Package__  :  Python 3
#  __GitHub__  : https://www.github.com/codeperfectplus
#
from node import Node


class LinkedList:
    def __init__(self):
        self.head = None
        self.counter = 0
        self.tail = None

    def __iter__(self):
        current = self.head
        while current:
            yield current
            current = current.next

    def __str__(self):
        if self.head is None:
            return "[]"
        nodes = [str(node.data) for node in self]
        return f"[{', '.join(nodes)}]"

    # O(N)
    def traverse(self):
        nodes = [str(node.data) for node in self]
        return " -> ".join(nodes)

    # O(1)
    def insert_start(self, value):
        self.counter += 1
        node = Node(value)
        if not self.head:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node

    # O(1)
    def size(self):
        return self.counter

    # O(1)
    def insert_end(self, value):
        self.counter += 1
        node = Node(value)
        if self.head is None:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node

    # O(N)
    def remove(self, value):
        if self.head is None:
            raise ValueError(
                "LinkedList.remove(value): \
                value not in LinkedList"
            )
        current = self.head
        prev = self.head
        while current:
            if current.data == self.head.data and current.data == value:
                self.head = self.head.next
                self.counter -= 1
                return
            if current.data == value:
                prev.next = current.next
                self.counter -= 1
                return
            prev = current
            current = current.next
        raise ValueError(
            "LinkedLis.remove(value): \
            value not in LinkedList"
        )
