"""This program creates a red black tree"""

#  Date   02/10/2020.
#   __Author__   :  Shivam
#  __Package__  :  Python 3.7
#  __GitHub__  : https://github.com/ugetshivam

"""Represents Node in this data structure"""


class Node:
    def __init__(self, value, color):
        self.value = value
        self.left = None
        self.right = None
        self.color = color


"""Red Black BST"""


class RedBlackBST:
    def __init__(self):
        self.root = None
        self.RED = True
        self.BLACK = False

    def compareTo(self, first, second):
        return first - second

    def isRed(self, node):
        if node is None:
            return False
        return node.color == self.RED

    def Rotateleft(self, h):
        assert self.isRed(h.right)
        x = h.right
        h.right = x.left
        x.left = h
        x.color = h.color
        h.color = self.RED
        return x

    def Rotateright(self, h):
        assert self.isRed(h.left)
        x = h.left
        h.left = x.right
        x.right = h
        x.color = h.color
        h.color = self.RED
        return x

    def flipColors(self, h):
        assert self.isRed(h.left)
        assert self.isRed(h.right)
        h.left.color = self.BLACK
        h.right.color = self.BLACK
        h.color = self.RED

    def Realinsert(self, x, value):
        if x is None:
            return Node(value, self.RED)
        cmp = self.compareTo(value, x.value)
        if cmp < 0:
            x.left = self.Realinsert(x.left, value)
        elif cmp > 0:
            x.right = self.Realinsert(x.right, value)
        else:
            x.value = value

        if self.isRed(x.right) and not self.isRed(x.left):
            x = self.Rotateleft(x)
        if self.isRed(x.left) and self.isRed(x.left.left):
            x = self.Rotateright(x)
        if self.isRed(x.left) and self.isRed(x.right):
            self.flipColors(x)

        return x

    def insert(self, value):
        self.root = self.Realinsert(self.root, value)

    def search(self, value):
        x = self.root
        while x is not None:
            cmp = self.compareTo(value, x.value)
            if cmp < 0:
                x = x.left
            elif cmp > 0:
                x = x.right
            else:
                return x.value
        return None

    """Hibbard Deletion"""

    def delete(self, value):
        self.root = self.Realdelete(self.root, value)

    def Realdelete(self, x, value):
        if x is None:
            return None
        cmp = self.compareTo(value, x.value)

        if cmp < 0:
            x.left = self.Realdelete(x.left, value)
        elif cmp > 0:
            x.right = self.Realdelete(x.right, value)
        else:
            if x.right is None:
                return x.left
            if x.left is None:
                return x.right

            t = x
            x = self.Min(t.right)
            x.right = self.deleteMin(t.right)
            x.left = t.left

        return x

    def deleteMin(self, x):
        if x.left is None:
            return x.right
        x.left = self.deleteMin(x.left)
        return x

    def Min(self, x):
        if x.left is None:
            return x
        return self.Min(x.left)

    def inorder(self):
        self.inorderRec(self.root)

    def inorderRec(self, root):
        if root is not None:
            self.inorderRec(root.left)
            print(root.value, end=" ")
            self.inorderRec(root.right)


if __name__ == "__main__":
    """The class name is RedBlackBST()
    After creating an object of this class, the client can
    use the following methods:
    1.object.insert(value): insert the value given
    to the BST
    2.object.search(value): this method would give you the
    node here this value exist
    3. object.delete(value): this method will delete
    the provided value form the tree
    4.object.inorder(): this method will print all the values
    in the tree in a non-decreasing order"""
