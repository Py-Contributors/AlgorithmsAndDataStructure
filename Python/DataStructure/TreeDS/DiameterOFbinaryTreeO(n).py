#Title:-DiameterOfBinaryTree
#Explanation:-https://www.youtube.com/watch?v=v8U4Wi6ZwKE&list=PLmpbOouoNZaP5M275obyC44n3I3nCFk8Q&index=12
#Author : Tanay Chauli
class newNode:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None


# Function to find height of a tree
def height(root, ans):
    if (root == None):
        return 0

    left_height = height(root.left, ans)

    right_height = height(root.right, ans)

    # update the answer, because diameter
    # of a tree is nothing but maximum
    # value of (left_height + right_height + 1)
    # for each node
    ans[0] = max(ans[0],left_height +
                 right_height)

    return 1 + max(left_height,
                   right_height)


# Computes the diameter of binary
# tree with given root.
def diameter(root):
    if (root == None):
        return 0
    ans = [-999999999999]  # This will store
    # the final answer
    height_of_tree = height(root, ans)
    return ans[0]


# Driver code
if __name__ == '__main__':
    root = newNode(1)
    root.left = newNode(2)
    root.right = newNode(3)
    root.left.left = newNode(4)
    root.left.right = newNode(5)

    print("Diameter is", diameter(root))
