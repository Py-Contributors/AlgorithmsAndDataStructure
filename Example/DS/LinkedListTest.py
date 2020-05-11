#  __Date__     : 1/5/2020.
#  __Author__   :  CodePerfectPlus
#  __Package__  :  Python 3
#  __GitHub__   : https://www.github.com/codeperfectplus
#
from DataStructures import LinkedList

myList = LinkedList()

myList.insertStart(11)
myList.insertEnd(19)
myList.insertEnd(10)


myList.treaverse()
print(f"Linked List Size : {myList.size()}")
