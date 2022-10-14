#include <iostream>
using namespace std;

// ************ THIS IS THE COMPLETE IMPLEMENTATION OF TRIE ************

// *********************************************************************
// Trie is very useful in solving dictionary related problems, like : 
// 1. search the given word in list of words
// 2. Print all the words in the dictionary starting with given letters
// *********************************************************************

// we need a tree like structure to create the link between the nodes
// creating a node structure, denoted by array of size 26, to represent 26 alphabets
// each node will have an end : if the end is marked true, means it is the end of the current word 

struct node
{
    node *arr[26];
    bool end;
    node()
    {
        end = false;
        for(int i=0;i<26;i++)
        {
            arr[i] = nullptr;
        }
    }

    bool contains(char c)
    {
        return arr[c - 'a'] != nullptr;
    }
};

// there are basically 3 operations in trie : 
// 1. Insert : inserting a word in the trie : TC : O(N)
// 2. Search : search the current word in the trie : TC : O(N)
// 3. isPrefix : to search whether the current word has some prefix maching in the trie : TC : O(N)

class Trie
{
    private : node *root;

    public:
    Trie()
    {
        root = new node();
    }

    void insert(string &s)
    {
        node *curr = root; // we use the previously appered prefixes in the trie to add new words, same prefixes are not repeated again and again
        for(char c : s)
        {
            if(!curr->contains(c))
            // creating new nodes and moving to next pointer
            curr->arr[c - 'a'] = new node();

            curr = curr->arr[c - 'a'];
        }
        curr->end = true; // marking end as true to represent the end of word
    }

    bool search(string &s)
    {
        node *curr = root;
        for(char c : s)
        {
            if(!curr->contains(c))
            return false;

            curr = curr->arr[c - 'a'];
        }
        return curr->end; // if the end is marked true, means the end of word, i.e., word matched
    }

    bool isPrefix(string &s)
    {
        node *curr = root;
        for(char c : s)
        {
            if(!curr->contains(c))
            return false;

            curr = curr->arr[c - 'a'];
        }
        return true; // return true if prefix matched
    }
};

int main()
{
    Trie t;

    string s = "apple";
    t.insert(s);
    string a = "app";
    cout<<t.search(s)<<endl<<t.isPrefix(a)<<endl;
    return 0;
}
