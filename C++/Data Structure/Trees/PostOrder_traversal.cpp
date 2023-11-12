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
    void postOrderTraversal_recursive(node *leaf);

public:
    binaryTree();
    void insertKeys(vector<int> keys);
    void insertKey(int key);
    void postOrderTraversal_recursive();
    void postOrderTraversal_iterative();
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
// The function travels down the tree starting from the root to find a suitable position.
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

// Recursive Post-Order Traversal
void binaryTree::postOrderTraversal_recursive()
{
    cout << "PostOrderTraversal (recursive): ";
    postOrderTraversal_recursive(root);
    cout << endl;
}

void binaryTree::postOrderTraversal_recursive(node *leaf)
{
    if (leaf != NULL)
    {
        postOrderTraversal_recursive(leaf->left);
        postOrderTraversal_recursive(leaf->right);
        cout << leaf->key_value << " ";
    }
}

// Iterative Post-Order Traversal
void binaryTree::postOrderTraversal_iterative()
{
    cout << "PostOrderTraversal (iterative): ";
    if (root == NULL)
        return;

    stack<node *> nodeAddr;
    node *currentNode = root;
    node *lastNodeVisited = NULL;

    while (!nodeAddr.empty() || currentNode != NULL)
    {
        if (currentNode != NULL)
        {
            nodeAddr.push(currentNode);
            currentNode = currentNode->left;
        }
        else
        {
            node *topNode = nodeAddr.top();

            if (topNode->right != NULL && lastNodeVisited != topNode->right)
            {
                currentNode = topNode->right;
            }
            else
            {
                cout << topNode->key_value << " ";
                lastNodeVisited = topNode;
                nodeAddr.pop();
            }
        }
    }
}

int main()
{
    binaryTree Tree;
    vector<int> elements = {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 80}; // The elements to be inserted in the tree
    Tree.insertKeys(elements);

    Tree.postOrderTraversal_recursive(); // Expected: 4 12 10 18 24 22 15 31 44 35 66 80 70 50 25
    Tree.postOrderTraversal_iterative(); // Expected: 4 12 10 18 24 22 15 31 44 35 66 80 70 50 25

    cout << endl;
}
