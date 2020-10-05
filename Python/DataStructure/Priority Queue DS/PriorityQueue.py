#  Date   05/10/2020.
#   __Author__   :  Divyanshu Bargali
#  __Package__  :  Python 3.x
#  __GitHub__  : https://github.com/div-bargali/

class Node:

    def __init__(self, info, priority):
        self.info = info
        self.priority = priority


class PriorityQueue:

    def __init__(self):
        self.queue = list()
        # if you want you can set a maximum size for the queue

    # O(n) insertion
    # Inserts new Node into the priority queue in increasing order of priority
    def insert(self, node):
        # if queue is empty
        if self.size() == 0:
            # add the new node
            self.queue.append(node)
        else:
            # traverse the queue to find the right place for new node
            for x in range(0, self.size()):
                # if the priority of new node is greater
                if node.priority >= self.queue[x].priority:
                    # if we have traversed the complete queue
                    if x == (self.size() - 1):
                        # add new node at the end
                        self.queue.insert(x + 1, node)
                    else:
                        continue
                else:
                    self.queue.insert(x, node)
                    return True

    # O(1) deletion
    def delete(self):
        # remove the first node from the queue
        return self.queue.pop(0)

    # Prints each element of the priority queue
    def show(self):
        for x in self.queue:
            print(str(x.info) + " - " + str(x.priority))

    # Returns the size of the priority queue
    def size(self):
        return len(self.queue)
