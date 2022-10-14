#include <iostream>
using namespace std;

// *********** THIS IS ANOTHER KIND OF IMPLEMENTATION OF TRIE DATA STRUCTURE **********
// THIS IS A CODE TO FIND COUNT OF WORDS :
// 1. WHICH MATCH WITH GIVEN WORDS
// 2. WHICH SATRT WITH GIVEN PREFIXES
// 3. TO ERASE THE GIVEN WORDS FROM OUR DICTIONARY 
// ************************************************************************************

struct node
{
    node *arr[26];
    int endCount; // to count the words which are matching exactly same
    int prefCount; // to count the words whose prefixes are matching
    
    node()
    {
        endCount = prefCount = 0;
        for(int i=0;i<26;i++)
            arr[i] = nullptr;
    }
    
    bool contains(char &c)
    {
        return arr[c - 'a'] != nullptr;
    }
};

class Trie
{
    private : node *root;
    public:

    Trie()
    {
        root = new node();
    }

    void insert(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                curr->arr[c - 'a'] = new node();
            
            curr = curr->arr[c - 'a'];
            curr->prefCount++; // incrementing the prefix count
        }
        curr->endCount++; // incrementing the complete words count
    }

    int countWordsEqualTo(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                return 0;
            
            curr = curr->arr[c - 'a'];
        }
        return curr->endCount; // returning the number of words which are exactly matching
    }

    int countWordsStartingWith(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                return 0;
            
            curr = curr->arr[c - 'a'];
        }
        return curr->prefCount; // returning the number of words whose prefixes are matching
    }

    void erase(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                return;
            
            curr = curr->arr[c - 'a'];
            curr->prefCount--; // decrementing the count of prefix count
        }
        curr->endCount--; // decrementing the count of words count
    }
};
