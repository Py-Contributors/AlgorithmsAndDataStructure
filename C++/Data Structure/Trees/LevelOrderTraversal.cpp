/*
   Level order traversal of a binary search Tree
   This is an algorithm to traverse through a binary search tree level by level
   Time complexity for level order traversal: O(N) where N is the number of nodes in the tree
*/
#include<bits/stdc++.h>
using namespace std;

//implementation of binary Tree - very minimal, only used to show implementation of level order traversal
class BinarySearchTree{
private:

    struct Node{
        int val;
        Node* left;
        Node* right;
        Node(int x): val(x), left(nullptr), right(nullptr){}
    };
    Node* treeRoot;
    //for the purposes of only demonstrating the level order traversal algorithm,
    //removing a node will not be implemented
    Node* insertNode(int key, Node* root)
    {
        if(root == nullptr){
            return new Node(key);
        }
        if(key < root->val){
            root->left = insertNode(key, root->left);
        }
        else if(key > root->val){
            root->right = insertNode(key, root->right);
        }
        return root;
    }
    //function to print level order traversal of a BST
    void printLevelOrder(Node* root)
    {
        //base case
        if(root == nullptr){
            return;
        }
        queue<Node*> nodes; //empty queue for level order traversal of tree
        nodes.push(root); //enqueue the trees root
        while(!nodes.empty()) //once the queue is empty, traversal is complete
        {
            Node* node = nodes.front();
            cout << node->val << " "; //print value of front of queue
            nodes.pop(); //dequeue front element
            //enqueue left and right children:
            if(node->left != nullptr){
                nodes.push(node->left);
            }
            if(node->right != nullptr){
                nodes.push(node->right);
            }
        }

    }

public:
    BinarySearchTree():treeRoot(nullptr){}
    void insert(int key)
    {
        treeRoot = insertNode(key, treeRoot);
    }
    void levelOrder()
    {
        printLevelOrder(treeRoot);
    }

};

int main(){
    //creating a tree with 7 nodes to demonstrate traversal
    BinarySearchTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    /* tree structure:
          4
         / \
        2   6
       /\   /\
      1  3 5  7

      output will be: 4 2 6 1 3 5 7
    */
    tree.levelOrder();
    return 0;
}
