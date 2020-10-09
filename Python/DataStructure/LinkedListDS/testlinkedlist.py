"""
Title - Linked List implementation in Python
This file provides a class implementation of the linked list
data structure in Python
"""


import unittest


from linkedlist import LinkedList


class TestLinkedList(unittest.TestCase):
    def test_linked_list_empty(self):
        llist = LinkedList()
        self.assertEqual(str(llist), "[]")

    def test_linked_list_insert_start(self):
        llist = LinkedList()
        llist.insert_start(1)
        self.assertEqual(str(llist), "[1]")

    def test_linked_list_insert_start_twice(self):
        llist = LinkedList()
        llist.insert_start(1)
        llist.insert_start(2)
        self.assertEqual(str(llist), "[2, 1]")

    def test_linked_list_insert_end(self):
        llist = LinkedList()
        llist.insert_end(3)
        llist.insert_end(4)
        self.assertEqual(str(llist), "[3, 4]")

    def test_linked_list_insert_end_then_start(self):
        llist = LinkedList()
        llist.insert_end(3)
        llist.insert_start(4)
        self.assertEqual(str(llist), "[4, 3]")

    def test_linked_list_insert_start_then_end(self):
        llist = LinkedList()
        llist.insert_start(4)
        llist.insert_end(3)
        self.assertEqual(str(llist), "[4, 3]")

    def test_linked_list_traversing(self):
        llist = LinkedList()
        for i in range(10):
            llist.insert_end(i)
        self.assertEqual(
            llist.traverse(), "0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9"
        )

    def test_linked_list_remove_error(self):
        llist = LinkedList()
        for i in range(10):
            llist.insert_end(i)
        with self.assertRaises(ValueError):
            llist.remove(60)

    def test_linked_list_remove(self):
        llist = LinkedList()
        for i in range(10):
            llist.insert_end(i)
        llist.remove(4)
        self.assertEqual(str(llist), "[0, 1, 2, 3, 5, 6, 7, 8, 9]")


if __name__ == "__main__":
    unittest.main()
