"""
Title - Linked List implementation in Python
The Node class is a supporting class for the
implementation of the LinkedList class
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
