#Title:-zigzagTreeTraversal
#Author : Tanay Chauli
class newNode:
    def __init__(self,val):
        self.val=val
        self.left=None
        self.right=None

def zigzagLevelOrder(root):
    if root is None:
        return
    res = []
    level = 0
    zigzagHelper(root, level, res)
    return res
def zigzagHelper(root, level, res):
    if root is None:
        return
    if len(res) < level + 1:
        res.append([])
    if  level%2==1:
        res[level].append(root.val)
    else:
        res[level].insert(0,root.val)
    zigzagHelper(root.left, level + 1, res)
    zigzagHelper(root.right, level + 1, res)
if __name__ == '__main__':
    root = newNode(5)
    root.left = newNode(9)
    root.left.right = newNode(16)
    root.right = newNode(3)
    root.right.left = newNode(15)
    root.left.left = newNode(6)
    root.right.right = newNode(4)
    root.right.right.left= newNode(11)
    root.right.right.right= newNode(14)
    root.left.left.left = newNode(8)
    root.left.left.right = newNode(7)
    print(zigzagLevelOrder(root))
