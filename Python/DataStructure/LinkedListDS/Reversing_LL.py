class Node(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        #here self is acting as l1
        result = ''

        while self:
            result += str(self.val)
            result += ' '
            self = self.next
        return result


class Solution(object):
    def reverse_ll(self, l1):
        curr = l1
        prev = None
        while curr != None:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev


l1 = Node(1)
l1.next = Node(2)
l1.next.next = Node(3)
print(Solution().reverse_ll(l1))
