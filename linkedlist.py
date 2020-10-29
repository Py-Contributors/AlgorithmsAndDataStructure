# Node class 
class Node: 
    # Function to initialise the node object 
    def __init__(self, data): 
        self.data = data  # Assign data 
        self.next = None  # Initialize next as null 
  
  
# Linked List class contains a Node object 
class LinkedList: 
  
    # Function to initialize head 
    def __init__(self): 
        self.head = None

    # function to insert all the elements in linked list
    def insert(self, x):
        for i in x:
            p = Node(i)
            if self.head==None:
                self.head=p
            else:
                b.next=p
            b = p

    # function to nisert element at given location
    def insert_at(self,i,d):
        j = 0
        prev = None
        b = self.head
        while j<i and b.next!=None :
            prev = b
            b = b.next
            j += 1
        
        a = Node(d)
        if j!=i:
            b.next = a
        else:
            a.next = b
            if prev == None:
                self.head = a
            else:
                prev.next = a
    # function to display all the elements of linked list
    def display(self):
        b = self.head
        while b.next!=None:
            print(b.data)
            b = b.next
        print(b.data)
    # function to delete element from the given location    
    def delete(self,i):
        if i == 0:
            self.head = self.head.next
            return 0

        j = 1
        b = self.head
        while j<i and b.next!=None :
            b = b.next
            j += 1
        try :
            b.next= b.next.next
        except:   
            print("Invalid index !!!!!!!! ")
  

# Code execution starts here 
if __name__=='__main__': 
  
    x = input("Enter the elements of linked list  (in space saparated format) : ").split()
    a = LinkedList()
    # calling insert function to insert all the elements
    a.insert(x)
    print("**********Linked list after inserting all the element ************")
    a.display()

    i = int(input("Enter the index at which the new data has to be inserted (NOTE that index should be less than or equal to total no of elements in list ): "))
    data = input("Enter the new data which has to inserted at the given index : ")
    
    # calling insert_at function to insert given element at given index
    a.insert_at(i,data)
    print("**********Linked list after inserting the given element at given index ************")
    a.display()

    i = int(input("Enter the index whose element is to be deleted : "))
    
    # calling delete function to delete element from given index 
    a.delete(i)
    
    print("**********Linked list after deleting the element from the given index ************")
    a.display()