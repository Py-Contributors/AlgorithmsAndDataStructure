# GIvena a binary tree, we have to find all the duplicate subtrees.
# for each duplicate subtrees we only need the root node of any one of them
# For this we are going to solve using inorder traversal.


# Creating a new node with the given data
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def inorder(root, m):
    if root is None:
        return ""
    s = "("
    s += inorder(root.left, m)
    s += str(root.data)
    s += inorder(root.right, m)
    s += ")"
    # Here i am using unordered_map instead of unordered_set because according to the
    # question we need to print duplicates only once.
    if s in m and m[s] == 1:
        print(root.data, end=" ")
    if s in m:
        m[s] += 1
    else:
        m[s] = 1
    return s


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.right.left = Node(2)
root.right.left.left = Node(4)
root.right.right = Node(4)
root.right.right.left = Node(4)
root.right.right.left = Node(4)
m = {}
inorder(root, m)
