#!python3
import math


class Node:
    def __init__(self, parent, key):
        self.parent = parent
        self.left = None
        self.right = None
        self.key = key


class AVLTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def height_node(self, node):
        if node is None:
            return -1
        else:
            return max(self.height_node(node.left), self.height_node(node.right))+1

    def height_tree(self):
        return math.floor(1+math.log2(self.size))

    def left_rotate(self, B):
        A = B.parent
        temp = B.left
        B.parent = A.parent
        if A.parent is None:
            self.root = B
        else:
            if A.parent.left is A:
                A.parent.left = B
            else:
                A.parent.right = B
        B.left = A
        A.parent = B
        A.right = temp

    def right_rotate(self, B):
        A = B.parent
        temp = B.right
        B.parent = A.parent
        if A.parent is None:
            self.root = B
        else:
            if A.parent.left is A:
                A.parent.left = B
            else:
                A.parent.right = B
        B.right = A
        A.parent = B
        A.left = temp

    def rebalance(self, node):
        while node is not None:
            if self.height_node(node.left)-self.height_node(node.right) >= 2:
                if self.height_node(node.left.left) > self.height_node(node.left.right):
                    self.right_rotate(node.left)
                else:
                    self.left_rotate(node.left.right)
                    self.right_rotate(node.left)
            elif self.height_node(node.right)-self.height_node(node.left) >= 2:
                if self.height_node(node.right.left) < self.height_node(node.right.right):
                    self.left_rotate(node.right)
                else:
                    self.right_rotate(node.right.left)
                    self.left_rotate(node.right)
            node = node.parent

    def insert_node(self, node, key):
        if node.key > key:
            if node.left is None:
                node.left = Node(node, key)
                return node
            else:
                return self.insert_node(node.left, key)
        else:
            if node.right is None:
                node.right = Node(node, key)
                return node
            else:
                return self.insert_node(node.right, key)

    def insert(self, key):
        if self.root:
            node = self.insert_node(self.root, key)
            self.rebalance(node.parent)
        else:
            self.root = Node(self.root, key)
        self.size += 1

    def print_levelorder_node(self, node, level):
        if node:
            if level == 0:
                print(node.key, end=' ')
            else:
                self.print_levelorder_node(node.left, level-1)
                self.print_levelorder_node(node.right, level-1)

    def print_tree(self):
        for level in range(self.height_tree()+1):
            self.print_levelorder_node(self.root, level)


if __name__ == "__main__":
    arr = [4, 2, 10, 1, 6, 3, 12, 5, 11, 7, 13, 8]
    # output => 6 4 10 2 5 7 12 1 3 8 11 13 (two rotations, first right rotate then left rotate)
    tree = AVLTree()
    for key in arr:
        tree.insert(key)
    tree.print_tree()
