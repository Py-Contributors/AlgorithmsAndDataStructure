#!python3
import math


class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.key = key


class BinaryTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def find_node_(self, node, key):
        if node:
            if node.key == key:
                return True
            if node.key > key:
                if self.find_node_(node.left, key):
                    return True
            else:
                if self.find_node_(node.right, key):
                    return True
        return False

    def find_node(self, key):
        if self.root == key:
            return True
        else:
            if self.find_node_(self.root, key):
                return True
        return False

    def insert_node(self, node, key):
        if node.key > key:
            if node.left is None:
                node.left = Node(key)
            else:
                self.insert_node(node.left, key)
        else:
            if node.right is None:
                node.right = Node(key)
            else:
                self.insert_node(node.right, key)

    def insert(self, key):
        if self.root:
            self.insert_node(self.root, key)
        else:
            self.root = Node(key)
        self.size += 1

    def height(self):
        return math.floor(1+math.log2(self.size))

    def print_inorder_node(self, node):
        if node:
            self.print_inorder_node(node.left)
            print(node.key, end=' ')
            self.print_inorder_node(node.right)

    def print_preorder_node(self, node):
        if node:
            print(node.key, end=' ')
            self.print_preorder_node(node.left)
            self.print_preorder_node(node.right)

    def print_postorder_node(self, node):
        if node:
            self.print_postorder_node(node.left)
            self.print_postorder_node(node.right)
            print(node.key, end=' ')

    def print_levelorder_node(self, node, level):
        if node:
            if level == 1:
                print(node.key, end=' ')
            else:
                self.print_levelorder_node(node.left, level-1)
                self.print_levelorder_node(node.right, level-1)

    def print_tree(self, traversal='level'):
        if self.root:
            if traversal == 'in':
                self.print_inorder_node(self.root)
            if traversal == 'pre':
                self.print_preorder_node(self.root)
            if traversal == 'post':
                self.print_postorder_node(self.root)
            if traversal == 'level':
                for level in range(self.height()+1):
                    self.print_levelorder_node(self.root, level)


if __name__ == "__main__":
    arr = [4, 2, 10, 1, 6, 3, 12, 5, 11, 7, 13, 8]
    # output => 4 2 10 1 3 6 12 5 7 11 13 (forms a BST)
    tree = BinaryTree()
    for key in arr:
        tree.insert(key)
    tree.print_tree()
