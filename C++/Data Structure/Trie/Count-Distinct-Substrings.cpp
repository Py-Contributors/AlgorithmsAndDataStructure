#include <iostream>
using namespace std;

struct node
{
    node *arr[26];
    bool end;
    node()
    {
        end = false;
        for(int i=0;i<26;i++)
            arr[i] = nullptr;
    }
    bool contains(char c)
    {
        return arr[c - 'a'] != nullptr;
    }
};

class Trie
{
    private : node *root;
    public :
    int count;
    Trie()
    {
        count = 1;
        root = new node();
    }
    void insert(string &s)
    {
        node *curr = root;
        for(char c : s)
        {
            if(!curr->contains(c))
            {
                curr->arr[c - 'a'] = new node();
//                 if inserting new substring, increment the count
                count++;
            }
            curr = curr->arr[c - 'a'];
        }
        curr->end = true;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie trie;
    for(int i=0;i<s.size();i++)
    {
        string word = s.substr(i);
        trie.insert(word);
    }
    return trie.count;
}
