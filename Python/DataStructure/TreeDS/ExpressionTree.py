#  Date   3/10/2020
#   __Author__   :  AdityaLata
#  __Package__  :  Python 3
#  __GitHub__  : https://www.github.com/adityalata

from Python.DataStructure.TreeDS.Node import Node


# A utility function to check if 'c' is an operator
def isOperator(c):
    if c == '+' or c == '-' or c == '*' or c == '/' or c == '^':
        return True
    else:
        return False


# Returns root of constructed tree for given postfix expression string
def getExpressionTree(postfix):
    stack = []

    # Traverse through every character of input expression
    for char in postfix:

        # for space separated postfix
        if char == " ":
            continue

        # if operand, simply push into stack
        elif not isOperator(char):
            t = Node(char)
            stack.append(t)

        # Operator
        else:

            # Pop two top nodes
            t = Node(char)
            t1 = stack.pop()
            t2 = stack.pop()

            # make them children
            t.right = t1
            t.left = t2

            # Add this subexpression to stack
            stack.append(t)

        # Only element will be the root of expression tree
    t = stack.pop()

    return t


# Returns value evaluated from given root of valid(full binary tree) expression tree
def evaluateExpressionTree(rootNode):
    # empty tree
    if rootNode is None:
        return 0

    # leaf node
    if rootNode.left is None and rootNode.right is None:
        return int(rootNode.value)

    # evaluate left tree
    leftSubtreeValue = evaluateExpressionTree(rootNode.left)

    # evaluate right tree
    rightSubtreeValue = evaluateExpressionTree(rootNode.right)

    # check which operation to apply on non leaf node
    if rootNode.value == '+':
        return leftSubtreeValue + rightSubtreeValue

    elif rootNode.value == '-':
        return leftSubtreeValue - rightSubtreeValue

    elif rootNode.value == '*':
        return leftSubtreeValue * rightSubtreeValue

    elif rootNode.value == '^':
        return leftSubtreeValue ** rightSubtreeValue

    elif rootNode.value == '/':
        return leftSubtreeValue / rightSubtreeValue
