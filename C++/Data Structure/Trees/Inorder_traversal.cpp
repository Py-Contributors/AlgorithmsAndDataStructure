#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Every node of the binary tree is represented by a 'node' data type
struct node
{
    int key_value; // Value the node holds
    node *left;    // Address of its left child
    node *right;   // Address of its right child
};

class binaryTree
{
private:
    node *root;
    void insertKey(int key, node *leaf);
    void inOrderTraversal_recursive(node *leaf);

public:
    binaryTree();
    void insertKeys(vector<int> keys);
    void insertKey(int key);
    void inOrderTraversal_recursive();
    void inOrderTraversal_iterative();
};

// Constructor. Initializes root to NULL.
binaryTree::binaryTree()
{
    root = NULL;
}

// Accepts a vector and calls insertKey(int) iteratively.
void binaryTree::insertKeys(vector<int> keys)
{
    int len = keys.size();
    for (int i = 0; i < len; i++)
    {
        insertKey(keys[i]);
    }
}

// When called for the first time (when root IS initialized as NULL), insertKey(int)
// initializes root to point to a node data type. This node data type gets its key_value
// as the key (argument) and child nodes as NULL.
// For all calls other than the first time, it further calls insertKey(int, node*).
void binaryTree::insertKey(int key)
{
    if (root != NULL)
    {
        insertKey(key, root);
    }
    else
    {
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

// Inserts the key, such that the tree follows the definition of a binary tree.
// The function traverses down the tree starting from the root to find a suitable position.
// If the key is less than the key_value at a node, the function calls itself with its left subtree.
// If the key is greater than or equal to the key_value at a node, the function calls itself with its right subtree.
// When it reaches a suitable place, it creates a new node. This node gets key_value as the key and child nodes as NULL.
void binaryTree::insertKey(int key, node *leaf)
{
    if (key < leaf->key_value)
    {
        if (leaf->left != NULL)
        {
            insertKey(key, leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->key_value)
    {
        if (leaf->right != NULL)
        {
            insertKey(key, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

// Calls inOrderTraversal_recursive, a private member-function.
void binaryTree::inOrderTraversal_recursive()
{
    cout << "InOrderTraversal (recursive): ";
    inOrderTraversal_recursive(root);
    cout << endl;
}

// For a particular node, the function prints its key_value and recursively calls
// its left and right subtrees (in that order).
void binaryTree::inOrderTraversal_recursive(node *leaf)
{
    if (leaf != NULL)
    {
        inOrderTraversal_recursive(leaf->left);
        cout << leaf->key_value << " ";
        inOrderTraversal_recursive(leaf->right);
    }
}

// The iterative in-order traversal function.
void binaryTree::inOrderTraversal_iterative()
{
    cout << "InOrderTraversal (iterative): ";
    if (root == NULL)
        return;
    stack<node *> nodeAddr;
    node *currentNode = root;

    while (currentNode != NULL || !nodeAddr.empty())
    {
        while (currentNode != NULL)
        {
            nodeAddr.push(currentNode);
            currentNode = currentNode->left;
        }
        if (!nodeAddr.empty())
        {
            currentNode = nodeAddr.top();
            nodeAddr.pop();
            cout << currentNode->key_value << " ";
            currentNode = currentNode->right;
        }
    }
}

int main()
{
    binaryTree Tree;
    vector<int> elements = {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 80};
    Tree.insertKeys(elements);

    Tree.inOrderTraversal_recursive(); // Expected: 4 10 12 15 18 22 24 25 31 35 44 50 66 70 80
    Tree.inOrderTraversal_iterative(); // Expected: 4 10 12 15 18 22 24 25 31 35 44 50 66 70 80

    cout << endl;

    return 0;
}
