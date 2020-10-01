#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
 
void postorder(struct Node* node)
{
    if (node == NULL)
        return;
        
    postorder(node->left);
    postorder(node->right);
    cout <<node->data << " ";
}
 
void inorder(struct Node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
 
void preorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left); 
    preorder(node->right);
} 
 
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
 
    cout << "\nPreorder traversal of binary tree is \n";
    preorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    inorder(root); 
 
    cout << "\nPostorder traversal of binary tree is \n";
    postorder(root);
 
    return 0;
}
