# Program: Tree Implementation. Insertion and Deletion
# __Author__: ExpressHermes

class TreeNode:
    ''' Tree Node Class '''

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        ''' Insert key at first available node
            Do a level order traversal of tree using
            queue. The new node is placed at he first
            empty left/right children of a node
        '''
        if not self.root:
            # if tree is empty
            self.root = TreeNode(key)
        else:
            q = [self.root]
            while q:
                # deque
                temp = q.pop(0)
                # check if the left children is node
                if not temp.left:
                    temp.left = TreeNode(key)
                    break
                q.append(temp.left)

                # check if the right children is None
                if not temp.right:
                    temp.right = TreeNode(key)
                    break
                q.append(temp.right)
        return self.root

    def delete(self, key):
        ''' Delete the node with val == key.
            Find the node to be deleted. Replace
            it with the rightmost deepest node. Delete
            the rightmost deepest node
        '''

        # if root or it's children are to be deleted
        if not self.root:
            return None
        elif not self.root.left and not self.root.right:
            if self.root.val == key:
                return None
            else:
                return self.root

        del_node = None
        q = [self.root]

        while q:
            temp = q.pop(0)
            if temp.val == key:
                del_node = temp
            if temp.left:
                q.append(temp.left)
            if temp.right:
                q.append(temp.right)
        if del_node:
            x = temp.val
            self.deleteDeepest(self.root, temp)
            del_node.val = x
        return self.root

    def deleteDeepest(self, node, d_node):
        ''' Find and delete the deepest rightmost node '''
        q = []
        q.append(node)
        while(len(q)):
            temp = q.pop(0)
            if temp is d_node:
                temp = None
                return
            if temp.right:
                if temp.right is d_node:
                    temp.right = None
                    return
                else:
                    q.append(temp.right)
            if temp.left:
                if temp.left is d_node:
                    temp.left = None
                    return
                else:
                    q.append(temp.left)

    def printInOrder(self, node):
        ''' Print inorder traversal of tree '''
        if node.left:
            self.printInOrder(node.left)
        print(node.val, end=' ')
        if node.right:
            self.printInOrder(node.right)
