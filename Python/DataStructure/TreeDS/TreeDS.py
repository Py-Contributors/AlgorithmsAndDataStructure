# Program: Tree Implementation. Insertion and Deletion
# __Author__: ExpressHermes
# __Author__: Yannick Brenning

class TreeNode:
    """ Tree Node Class """

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        """ Insert key at first available node
            Do a level order traversal of tree using
            queue. The new node is placed at he first
            empty left/right children of a node
        """

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
        """ Delete the node with val == key.
            Find the node to be deleted. Replace
            it with the rightmost deepest node. Delete
            the rightmost deepest node
        """

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
            self.delete_deepest(self.root, temp)
            del_node.val = x
        return self.root

    def delete_deepest(self, node, d_node):
        """ Find and delete the deepest rightmost node """
        q = [node]
        while len(q):
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

    def print_inorder(self, node):
        """ Print inorder traversal of tree """
        if node.left:
            self.print_inorder(node.left)
        print(node.val, end=' ')
        if node.right:
            self.print_inorder(node.right)

    def is_bst(self):
        """
        Checks if the Tree is a Binary Search Tree by definition
        See also: https://en.wikipedia.org/wiki/Binary_search_tree#Definition
        """

        return self.__is_bst(self.root)

    def __is_bst(self, node):
        """
        Checks if the subtree of a given node is a valid BST
        :return validity as bool value
        """

        if node is None:
            return True

        # Check if the left subtree is less and right is greater
        # than the current node, then repeat the process for every other
        # node in the tree by making recursive calls for left and right subtrees
        return \
            self.__is_subtree_lesser(node.left, node.val) \
            and self.__is_subtree_greater(node.right, node.val) \
            and self.__is_bst(node.left) and self.__is_bst(node.right)

    def __is_subtree_lesser(self, node, val):
        if node is None:
            return True

        return \
            val >= node.val \
            and self.__is_subtree_lesser(node.left, val) \
            and self.__is_subtree_lesser(node.right, val)

    def __is_subtree_greater(self, node, val):
        if node is None:
            return True

        return \
            val < node.val \
            and self.__is_subtree_greater(node.left, val) \
            and self.__is_subtree_greater(node.right, val)


def main():

    # Basic driver code to demonstrate methods

    tree = Tree()
    tree.insert(50)
    tree.insert(25)
    tree.insert(75)
    tree.insert(60)
    tree.print_inorder(tree.root)

    # The insert() method of the Tree class does
    # not insert nodes according to the BST definition,
    # meaning that this will return False
    print(f"\n{tree.is_bst()}")

    bst = Tree()
    bst.root = TreeNode(50)
    bst.root.left = TreeNode(25)
    bst.root.right = TreeNode(75)
    bst.root.right.left = TreeNode(60)
    bst.print_inorder(bst.root)

    # We have manually constructed a valid BST,
    # meaning that this will return True
    print(f"\n{bst.is_bst()}")


if __name__ == '__main__':
    main()
