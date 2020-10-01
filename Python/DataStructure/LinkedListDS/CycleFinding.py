from .LinkedList import LinkedList


def hasCycle(head):
    '''
    returns the node where the cycle starts
    Or returns false if no cycle present
    '''
    fastptr, slowptr = head, head
    if fastptr.nextNode is None or fastptr.nextNode.nextNode is None:
        return False
    while True:
        slowptr = slowptr.nextNode
        fastptr = fastptr.nextNode.nextNode
        if fastptr == slowptr:
            break

    slowptr = head

    while True:
        slowptr = slowptr.nextNode
        fastptr = fastptr.nextNode
        if fastptr == slowptr:
            break

    return fastptr


# driver code for printing output
ll = LinkedList()
ll.insertEnd(1)
ll.insertEnd(2)
ll.insertEnd(3)
ll.insertEnd(4)
ll.insertEnd(5)
ll.insertEnd(6)
a = ll.head.nextNode.nextNode.nextNode.nextNode.nextNode
a.nextNode = ll.head.nextNode.nextNode
print(hasCycle(ll.head).data)
