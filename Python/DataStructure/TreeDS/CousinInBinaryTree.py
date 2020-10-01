#Title:-CousinInBinaryTree
#Author : Tanay Chauli
from collections import defaultdict


class Node:

    def __init__(self, item):
        self.val = item
        self.left = None
        self.right = None
def IsCousin(root,x,y):
    level=0
    parent=None
    stack=[(root,parent,level)]
    dic=defaultdict()
    while stack:
        node,parent,level=stack.pop()
        dic[node.val]=[parent,level]
        if node.left:
            stack.append((node.left,node,level+1))
        if node.right:
            stack.append((node.right,node,level+1))
    a=dic[x][0]
    b=dic[x][1]
    a2=dic[y][0]
    b2=dic[y][1]
    return (dic[x][0] != dic[y][0] and dic[x][1] == dic[y][1])


if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.left.right.right = Node(15)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.right.left.right = Node(8)
    print(IsCousin(root,5,7))
