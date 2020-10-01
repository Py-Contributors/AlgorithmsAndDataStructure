#Title:-HeightOfBinaryTree
#Author : Tanay Chauli
class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
def insert(root,data):
    if root==None:
        root=Node(data)
    elif root.data>data:
        root.left=insert(root.left,data)
    elif root.data<data:
        root.right=insert(root.right,data)
    return root
def maxHeightBst(root):
    if root is None:
        return  0
    lHight=maxHeightBst(root.left)
    rHight=maxHeightBst(root.right)
    return max(rHight,lHight)+1

root=None
root=insert(root,2)
insert(root,1)
insert(root,3)
insert(root,4)
insert(root,5)
print(maxHeightBst(root))
