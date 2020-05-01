#  Copyright (c) 2020.
#  __Author__   :  CodePerfectPlus
#  __Package__  :  Python 3
#  __GitHub__  : https://www.github.com/codeperfectplus
#

class Node:
    def __init__(self,data):
        self.data = data
        self.nextNode = None

    def remove(self,data,previousNode):
        if self.data == data:
            previousNode.nextNode = self.nextNode
            del self.data
            del self.nextNode
        else:
            if self.nextNode is not None:
                self.nextNode.remove(data,self)