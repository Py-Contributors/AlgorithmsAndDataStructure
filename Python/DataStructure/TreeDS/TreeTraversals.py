#  Date   3/10/2020
#   __Author__   :  AdityaLata
#  __Package__  :  Python 3
#  __GitHub__  : https://www.github.com/adityalata

# A utility function to do inOrder traversal
def inOrder(t):
    if t is not None:
        inOrder(t.left)
        print(t.value)
        inOrder(t.right)


# A utility function to do postOrder traversal
def postOrder(t):
    if t is not None:
        postOrder(t.left)
        postOrder(t.right)
        print(t.value)


# A utility function to do preOrder traversal
def preOrder(t):
    if t is not None:
        print(t.value)
        postOrder(t.left)
        postOrder(t.right)
