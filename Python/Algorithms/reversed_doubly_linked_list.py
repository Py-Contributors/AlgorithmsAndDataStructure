class Node: 
    # Function to initialise the node object 
    def __init__(self, data): 
        self.data = data  # Assign data 
        self.prev = None  # Initialize previous as null
        self.next = None  # Initialize next as null 
  
  
# Linked List class contains a Node object 
class Doubly_LinkedList: 
  
    # Function to initialize head 
    def __init__(self): 
        self.head = None
        self.last_element = None

    # function to insert all the elements in Doubly linked list
    def insert(self, x):
        for i in x:
            p = Node(i)
            if self.head==None:
                self.head=p

            else:
                b.next = p
                p.prev = b
            b = p
        self.last_element = b
        


    # function to display all the elements of linked list
    def display(self):
        b = self.head
        while b.next!=None:
            print(b.data)
            b = b.next
        print(b.data)
    
    # function to print the reverse of doubly linked list 
    # by back tracking from the last element
    def reverse(self):
        b = self.last_element
        while(b.prev!=None):
            print(b.data, end=" ")
            b = b.prev
        print(b.data)

if __name__=='__main__': 
  
    t = int(input("Enter the no. of test cases : "))
    
    for i in range(t):
        arr = []
        a = Doubly_LinkedList()

        n = int(input("Enter the no of elements in the linked list : "))
        for j in range(n):
            arr.append(input().strip())
        
        a.insert(arr)
        print("Linked list in reverse order : ")
        a.reverse()
        # deleting the object of class !
        del(a)
