/* Trie Implementation
 *      Tree like data structure with nodes of the tree storing the entire alphabet
 *      strings can be search by traversing through the tree
 *      Time Complexity search=insert=remove= O(length of longest key * total number of keys) = O(mn)
*/
#include <iostream>
using namespace std;
#define ALPHA_SIZE 26

//structure of trie node
struct TrieNode{
    TrieNode* children[ALPHA_SIZE];
    //check if the word entered into the tree has come to an end
    bool isEnd;
};
//return new trie node
struct TrieNode *getNode(void){
    struct TrieNode *node = new TrieNode;
    node->isEnd= false;
    for(int i=0; i<ALPHA_SIZE; i++){
        node->children[i] = nullptr;
    }
    return node;
}
void insert(struct TrieNode* root, string key){
    struct TrieNode * pCrawl = root;
    //iterate through tree node to see if each alphabet in key is present
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        //if not present in trie, add it
        if(!pCrawl->children[index]){
            pCrawl->children[index]=getNode();
        }
        pCrawl=pCrawl->children[index];
    }
    //set last node as true, end of word
    pCrawl->isEnd=true;
}
//check if root node has children (true) or not (false)
bool hasChildren(TrieNode* root){
    //iterate through alphabet size to see if root has children
    for(int i=0;i<ALPHA_SIZE;i++){
        if(root->children[i])
            return true;
    }
    return false;
}
//remove a word from trie
TrieNode* remove(TrieNode* root, string key, int height=0){
    //if tree is empty
    if(!root){
        return nullptr;
    }
    //last character being processed
    if(height==key.size()){
        if(root->isEnd)
            root->isEnd= false;
        //if there no children, delete root
        if(!hasChildren(root)){
            delete(root);
            root= nullptr;
        }
        return root;
    }


    int index = key[height]-'a';
    //recursion through characters in key
    root->children[index]=remove(root->children[index],key,height+1);
    //if root does not have children and is not end of word, delete root
    if(!hasChildren(root) && !root->isEnd){
        delete(root);
        root= nullptr;
    }
    return root;
}
//search for word in tree
bool search(TrieNode* root, string key){
    struct TrieNode *pCrawl = root;
    //iterate through key characters to find if key is present
    for(int i=0; i<key.length(); i++){
        int index = key[i]-'a';
        //if not present return false
        if(!pCrawl->children[index]){
            return false;
        }
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->isEnd;
}
//print statement
void print(bool isPresent, string key){
    isPresent? cout<<key<<" is in trie\n": cout<<key<<" is not in trie\n";
}
int main() {
    struct TrieNode *root = getNode();
    insert(root,"hello");
    insert(root, "gator");
    insert(root, "trie");
    insert(root, "hi");

    print(search(root,"hello"),"hello");
    remove(root, "hello");
    print(search(root,"hello"),"hello");
    print(search(root,"bye"),"bye");
    print(search(root,"hi"),"hi");

    return 0;
}