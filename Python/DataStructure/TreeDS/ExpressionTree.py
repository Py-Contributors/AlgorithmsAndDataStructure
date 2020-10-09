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

        # if operand, simply push into stack
        if not isOperator(char):
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
