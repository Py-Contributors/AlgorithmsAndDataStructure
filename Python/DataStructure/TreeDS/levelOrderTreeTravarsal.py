#Title:-Level Order Traversal
#Author : Tanay Chauli
import queue

class newNode:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None
        self.next=None
def LevelOrder(root):
    q=[root]
    res=[]
    while q:
        n=q.pop(0)
        res.append(n.val)
        if n.left:
            q.append(n.left)
        if n.right:
            q.append(n.right)
    return res

if __name__ == '__main__':
    root = newNode(5)
    root.left = newNode(9)
    root.right = newNode(3)
    root.left.left = newNode(6)
    root.right.right = newNode(4)
    root.left.left.left = newNode(8)
    root.left.left.right = newNode(7)
    print(LevelOrder(root))
