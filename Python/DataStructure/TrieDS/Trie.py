"""
Title - Trie Data Structure
Data structure to insert and search word efficiently
time complexity - O(n) where n=len(word)
"""


class LL:   # Linked List Data structure to store level wise nodes of Trie
    def __init__(self, val):
        self.val = val
        self.next = {}
        self.completed = False


class Trie:
    """
    Trie is also called as prefix tree
    """
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = LL(None)

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self.root
        for i in word:
            if i not in node.next:
                node.next[i] = LL(i)
            node = node.next[i]
        node.completed = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.root
        for i in word:
            if i not in node.next:
                return False
            node = node.next[i]
        return node.completed

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self.root
        for i in prefix:
            if i not in node.next:
                return False
            node = node.next[i]
        return True

# obj = Trie()
# obj.insert("python")
# param_2 = obj.search("python")
# param_3 = obj.startsWith("pyt")
# print(param_2)
# print(param_3)
