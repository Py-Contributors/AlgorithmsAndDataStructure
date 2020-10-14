#  Date   02/10/2020.
#   __Author__   :  Krishnan Navadia
#  __Package__  :  Python 3.x
#  __GitHub__  : https://github.com/krishnan-tech/
#
class Node():
    def __init__(self, data):
        self.next = None
        self.data = data


class LinkedList:
    def __init__(self):
        self.head = None

    def print_list(self):
        curr_node = self.head
        while curr_node:
            print(curr_node.data)
            curr_node = curr_node.next

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_after_node(self, prev_node, data):
        if not prev_node:
            print("Previous node is not in list")
            return
        new_node = Node(data)
        new_node.next = prev_node.next
        prev_node.next = new_node

    def delete_node(self, key):
        curr_node = self.head
        if curr_node and curr_node.data == key:
            self.head = curr_node.next
            curr_node = None
            return

        prev = None
        while curr_node and curr_node.data != key:
            prev = curr_node
            curr_node = curr_node.next
        if curr_node is None:
            return
        prev.next = curr_node.next
        curr_node = None

    def delete_node_at_position(self, position):
        curr_node = self.head
        if position == 0:
            self.head = curr_node.head
            curr_node = None
            return
        prev = None
        count = 1
        while curr_node and count != position:
            prev = curr_node
            curr_node = curr_node.next
            count += 1
        if curr_node is None:
            return
        prev.next = curr_node.next
        curr_node = None

    def len_iterative(self):
        curr_node = self.head
        count = 0
        while curr_node:
            count += 1
            curr_node = curr_node.next
        return (count)

    def len_recursive(self, node):
        if node is None:
            return 0
        return 1 + self.len_recursive(node.next)

    def swap_node(self, key1, key2):
        if key1 == key2:
            return
        prev_1 = None
        curr_1 = self.head

        while curr_1 and curr_1.data != key1:
            prev_1 = curr_1
            curr_1 = curr_1.next

        prev_2 = None
        curr_2 = self.head

        while curr_2 and curr_2.data != key2:
            prev_2 = curr_2
            curr_2 = curr_2.next
        if not curr_1 or not curr_2:
            return
        if prev_1:
            prev_1.next = curr_2
        else:
            self.head = curr_2
        if prev_2:
            prev_2.next = curr_1
        else:
            self.head = curr_1

        curr_1.next, curr_2.next = curr_2.next, curr_1.next

    def reverse_iterative(self):
        # A -> B -> C -> D -> 0
        # D -> C -> B -> A -> 0
        # A <- B <- C <- D <- 0
        prev = None
        curr = self.head
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        self.head = prev

    def reverse_recursive(self):
        def recursive_helper(curr, prev):
            if not curr:
                return prev
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            return recursive_helper(curr, prev)
        self.head = recursive_helper(curr=self.head, prev=None)

    def merge_sorted(self, llist):
        p = self.head
        q = llist.head
        s = None
        if not p:
            return q
        if not q:
            return p
        if p and q:
            if p.data <= q.data:
                s = p
                p = s.next
            else:
                s = q
                q = s.next
        while p and q:
            if p.data <= q.data:
                s.next = p
                s = p
                p = s.next
            else:
                s.next = q
                s = q
                q = s.next
        if not p:
            s.next = q
        else:
            s.next = p

    def remove_duplicates(self):
        prev = None
        curr = self.head
        dup_values = dict()
        while curr:
            if curr.data in dup_values:
                # remove node
                prev.next = curr.next
                curr = None
            else:
                dup_values[curr.data] = 1
                prev = curr
            curr = prev.next

    def print_nth_from_last(self, n):

        # # Method 1:
        # total_len = self.len_iterative()

        # cur = self.head
        # while cur:
        #     if total_len == n:
        #         print(cur.data)
        #         return cur
        #     total_len -= 1
        #     cur = cur.next
        # if cur is None:
        #     return

        # Method 2:
        p = self.head
        q = self.head

        count = 0
        while q and count < n:
            q = q.next
            count += 1

        if not q:
            print(str(n) + " is greater than the number of nodes in list.")
            return

        while p and q:
            p = p.next
            q = q.next
        return p.data

    def remove_nth_node_from_end(self, n):
        p = self.head
        q = self.head
        count = 0
        while q and count < n:
            q = q.next
            if not q:
                print(str(n) + " is greater than the number of nodes in list.")
                return
            count += 1
        if not q:
            self.head = p.next
            p = None
            return

        prev = None
        while p and q:
            prev = p
            p = p.next
            q = q.next

        prev.next = p.next
        p = None

    def count_occurances(self, data):
        count = 0
        curr = self.head
        while curr:
            if curr.data == data:
                count += 1
            curr = curr.next
        print(count)

    def rotate_llist(self, k):
        p = self.head
        q = self.head
        prev = None
        count = 0
        while p and count < k:
            prev = p
            p = p.next
            q = q.next
            count += 1
        p = prev

        while q:
            prev = q
            q = q.next
        q = prev

        q.next = self.head
        self.head = p.next
        p.next = None

    def is_palindrome(self):
        # Method 1
        # s = ""
        # p = self.head
        # while p:
        #     s+=p.data
        #     p=p.next
        # print(s==s[::-1])

        # Method 2
        # p=self.head
        # s=[]
        # while p:
        #     s.append(p.data)
        #     p=p.next

        # p = self.head
        # while p:
        #     data = s.pop()
        #     if p.data != data:
        #         return False
        #     p = p.next
        # return True

        # Method 3
        p = self.head
        q = self.head
        prev = []
        i = 0
        while q:
            prev.append(q)
            q = q.next
            i += 1
        q = prev[i - 1]

        count = 1
        while count <= i // 1 + 1:
            if prev[- count] != p.data:
                return False
        return True

    def tail_to_head(self):
        # A -> B -> C -> D -> 0
        # D -> A -> B -> C -> 0
        p = self.head
        prev = None
        while p.next:
            prev = p
            p = p.next

        p.next = self.head
        self.head = p
        prev.next = None
