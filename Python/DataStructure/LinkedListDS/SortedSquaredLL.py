
class Node(object):

    def __init__(self,d,n=None):
        self.data = d
        self.next_node = n

    def get_next(self):
        return self.next_node
    
    def set_next(self,n):
        self.next_node = n
    
    def get_data(self):
        return self.data
    
    def set_data(self,d):
        self.data = d

    def has_next(self):
        if self.get_next() is None:
            return False
        return True

    def to_string(self):
        return ("Node Val : "+str(self.data))

class LinkedList(object):
    def __init__(self,r=None):
        self.root = r
        self.size = 0
        
    def get_size(self):
        return self.size
    
    def add(self,d):
        new_node = Node(d,self.root)
        self.root = new_node
        self.size += 1

    def print_list(self):
        print("Printing a linked list...")
        if self.root is None:
            return
        this_node = self.root
        print(this_node.to_string())
        while this_node.has_next():
            this_node = this_node.get_next()
            print(this_node.to_string())
        
    def remove(self,d):
        this_node = self.root
        prev_node = None

        while this_node is not None:
            if this_node.get_data() == d:
                if prev_node is not None:
                    prev_node.set_next(this_node.get_next())
                else:
                    self.root = this_node.get_next()
                self.size -= 1
                return True
            else:
                prev_node = this_node
                this_node = this_node.get_next()
        return False
    
    def find(self,d):
        this_node = self.root
        while this_node is not None :
            if this_node.get_data() == d:
                return d
            elif this_node.get_next() == None:
                return False
            else:
                this_node = this_node.get_next()
            



#Adding linked list elements inascending order 

myList = LinkedList()
myList.add(5)
myList.add(9)
myList.add(8)
myList.add(11)
myList.add(12)

#driver code for printing the output

myList.print_list()
print("size="+str(myList.get_size()))
myList.remove(8)
print("size="+str(myList.get_size()))
print(myList.remove(12))
print("size="+str(myList.get_size()))
print(myList.find(5))
myList.print_list()


