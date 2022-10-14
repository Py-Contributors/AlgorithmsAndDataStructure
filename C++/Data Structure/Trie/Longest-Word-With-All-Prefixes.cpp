#include <iostream>
#include <vector>
using namespace std;

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

class Trie
{
    private : node *root;
    public :
    Trie()
    {
        root = new node();
    }
    void insert(string &a)
    {
        node *curr = root;
        for(char c : a)
        {
            if(!curr->contains(c))
                curr->arr[c - 'a'] = new node();
            curr = curr->arr[c - 'a'];
        }
       curr->end = true;
    }
    bool search(string &a)
    {
        node *curr = root;
        for(char c : a)
        {
            if(!curr->contains(c))
                return false;
            
            curr = curr->arr[c - 'a'];
//             if any of the prefix of curr word is not present as a word in vector
//             return false, ex : ning is not present as a word in vector
            if(curr->end == false)
                return false;
        }
        return true;
    }
};

// ex : a = {n ni nin ninj ninja ninga}
// op can be n, ni, nin, ninja
// among : longest and lexicographoc smallest is "ninja"
// not ninga, as "ning" is not present in a;

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    for(string &word : a)
    {
        t.insert(word);
    }
    string ans = "";
    for(string &word : a)
    {
        if(t.search(word))
        {
            if(word.size() > ans.size())
            {
                ans = word;
            }
            else if(word.size() == ans.size() && word < ans)
                ans = word;
        }    
    }
    return (ans == "" ? "None" : ans);
}
