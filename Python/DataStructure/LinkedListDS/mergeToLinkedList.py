#Title:- Merge Two LinkedList in Sorted Order
#Author:- Tanay Chauli

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Constructor to initialize the node object
class LinkedList:

    # Function to initialize head
    def __init__(self):
        self.head = None

    # Method to print linked list
    def printList(self):
        temp = self.head

        while temp:
            print(temp.data, end="->")
            temp = temp.next

    # Function to add of node at the end.
    def append(self, new_data):
        new_node = Node(new_data)

        if self.head is None:
            self.head = new_node
            return
        last = self.head

        while last.next:
            last = last.next
        last.next = new_node

    # Function to merge two sorted linked list.


def mergeLists(head1, head2):
    temp=None
    if head1 is None:
        return head2
    if head2 is None:
        return head1
    if head1.data<=head2.data:
        temp=head1
        temp.next=mergeLists(head1.next,head2)
    else:
        temp=head2
        temp.next=mergeLists(head1,head2.next)
    return temp
# Driver Function
if __name__ == '__main__':
    # Create linked list :
    # 10->20->30->40->50
    list1 = LinkedList()
    list1.append(10)
    list1.append(20)
    list1.append(30)
    list1.append(40)
    list1.append(50)

    # Create linked list 2 :
    # 5->15->18->35->60
    list2 = LinkedList()
    list2.append(5)
    list2.append(15)
    list2.append(18)
    list2.append(35)
    list2.append(60)

    # Create linked list 3
    list3 = LinkedList()

    # Merging linked list 1 and linked list 2
    # in linked list 3
    list3.head = mergeLists(list1.head, list2.head)

    print(" Merged Linked List is : ", end="")
    list3.printList()
