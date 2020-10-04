#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// every node of the binary tree is represented by a 'node' data type
struct node{
    int key_value;  // value the node holds
    node* left;     // address of its left child
    node* right;    // address of its right child
};

class binaryTree{
    private:
        node* root;
        void insertKey(int key, node* leaf);
        void preOrderTraversal_recursive(node* leaf);
    public:
        binaryTree();
        void insertKeys(vector<int> keys);
        void insertKey(int key);
        void preOrderTraversal_recursive();
        void preOrderTraversal_iterative();
};

// constructor. initializes root to NULL
binaryTree::binaryTree(){
    root = NULL;
}

// accepts a vector and calls insertKey(int) iteratively.
void binaryTree::insertKeys(vector<int> keys){
    int len = keys.size();
    for(int i=0;i<len;i++){
        insertKey(keys[i]);
    }
}

// When called for the first time(when root IS initialized as NULL), insertKey(int)
// initializes root to point to a node data type. This node data type gets it key_value
// as key(argument) and child nodes as NULL.
// For all calls other than the first time, it further calls insertKey(int, node*)
void binaryTree::insertKey(int key){
    if(root!=NULL){
        insertKey(key, root);
    }
    else{
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

// inserts the key, such that the Tree follows the definition of a binary tree.
// the function travels down the tree starting from the root to find a suitable position.
// if key is less than the key_value at a node, function calls itself with its left subtree.
// if key is greater than the key_value at a node, function calls itself with its right subtree.
// When it reaches a suitable place, it creates a new node. This node gets key_value as key and child nodes as NULL
void binaryTree::insertKey(int key, node* leaf){
    if(key< leaf->key_value){
        if(leaf->left!=NULL){
            insertKey(key, leaf->left);
        }
        else{
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if(key>= leaf->key_value){
        if(leaf->right!=NULL){
            insertKey(key, leaf->right);
        }
        else{
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

// calls preOrderTraversal_recursive, a private member-function
void binaryTree::preOrderTraversal_recursive(){
    cout<<"PreOrderTraversal(recursive): ";
    preOrderTraversal_recursive(root);
}

// for a particular node, function prints its key_value and recursively calls
// its left and right subtree(in that order).
void binaryTree::preOrderTraversal_recursive(node* leaf){
    if(leaf!=NULL){
        cout<<leaf->key_value<<" ";
        preOrderTraversal_recursive(leaf->left);
        preOrderTraversal_recursive(leaf->right);
    }
}

// if root is NULL, function exits
// otherwise, it works as follows: 1. Sets root as current node.
// 2. It outputs the key_value of the current node,
// and pushes the address of its right subtree in stack. Also, sets current node as address of its left subtree
// This continues till the current node is NULL.
// 3. When it reaches NULL i.e. no left subtree is available, it sets current node as top value in the
// stack and pops it from the stack. Then it repeats step 2.
void binaryTree::preOrderTraversal_iterative(){
    cout<<"PreOrderTraversal(iterative): ";
    if(root==NULL)
        return;
    stack<node*> nodeAddr;
    node* currentNode = root;

    while(currentNode!=NULL || !nodeAddr.empty()){
        while(currentNode!=NULL){
            cout<<currentNode->key_value<<" ";
            if(currentNode->right!=NULL){
                nodeAddr.push(currentNode->right);
            }
            currentNode = currentNode->left;
        }
        if(!nodeAddr.empty()){
            currentNode = nodeAddr.top();
            nodeAddr.pop();
        }
    }
}

int main(){
    binaryTree Tree;
    vector<int> elements = {25,15,50,10,22,35,70,4,12,18,24,31,44,66,80}; //the elements to be inserted in the tree
    Tree.insertKeys(elements);
    Tree.preOrderTraversal_recursive(); //expected: 25 15 10 4 12 22 18 24 50 35 31 44 70 66 80
    cout<<endl;
    Tree.preOrderTraversal_iterative(); //expected: 25 15 10 4 12 22 18 24 50 35 31 44 70 66 80
    cout<<endl;
}
