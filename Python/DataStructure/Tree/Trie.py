# Program: Trie Implementation. Insertion, Search, Search prefix
# __Author__: Ayush Jaipuriyar

class Trie(object):
    """
    A class named Trie for the main tree
    """

    def __init__(self):
        """
        Function to initialize the class Trie
        """
        self.words = {}

    def insert(self, word):
        """
        Function to insert a given word to the tree from variable tree
        :param word:The word passed down to the function
        :type word:str
        :return:Prints "The word, was successfully added"
        :rtype:none
        """
        current = self.words
        for alphabet in word:
            if alphabet not in current:
                current[alphabet] = {}
            current = current[alphabet]
        current['#'] = 1
        print("\nThe word,{} was successfully added \n".format(word))

    def search(self, word):
        """
        Function to search a word in the already existing tree
        :param word:The word passed to the function to be searched for
        :type word:str
        :return:True if the word exist in tree else false
        :rtype:bool
        """
        current = self.words
        for alphabet in word:
            if alphabet not in current:
                print("Word not found!")
            else:
                current = current[alphabet]
        return '#' in current

    def prefix_search(self, prefix):
        """
        Function to search for prefix letters in a tree
        :param prefix:The letters passed to search as a prefix to be searched
        :type prefix:str
        :return:True if the prefix exist in tree else false
        :rtype:bool
        """
        current = self.words
        for alphabet in prefix:
            if alphabet not in current:
                return False
            else:
                current = current[alphabet]
        return True


def menu_options():
    """
    Function to print the menu
    """
    print("Select your option ")
    print("\n1.Insert \n2.Search \n3.Preffix search \n4.Quit")


if __name__ == '__main__':
    ob1 = Trie()
    while True:
        menu_options()
        choice = input("\nchoice:-")
        if choice == '1':
            insert_word = input("Enter the word you want to add to the tree ")
            ob1.insert(insert_word)
        elif choice == '2':
            word_search = input("What do you want to search ")
            print("\nWord found successfully!!\n" if ob1.search(word_search)
                  else "\nWord not found!\n")
        elif choice == '3':
            prefix_letters = input("What do you want to search as prefix ")
            print("\nPrefix found successfully!!\n"
                  if ob1.prefix_search(prefix_letters)
                  else "\nPrefix not found!\n")
        else:
            break

