/*  Binary Search Tree implementation 
	In Binary Search tree left subtree is having smaller values than root
	right subtree has values larger than root
	Time Complexity for search = insertion = deletion = O(heightOfTre)= O(N)
*/

#include<bits/stdc++.h>
using namespace std;

class BinarySearchTree{

private:
	// this will be over structure of node 
	struct TreeNode{
		int val;
		TreeNode* left;
		TreeNode* right;
		};
	TreeNode* root;

	TreeNode* insertNode(int x, TreeNode* root){
		// if the root is empty add value to the root node
		if(root==NULL){
			root = new TreeNode;
			root->val = x;
			root->left = root-> right = NULL;
		}
		// if value is smaller than root then go to left of the tree
		else if(x < root->val){
			root->left = insertNode(x,root->left);
		}
		// if value is greater than root then go to right of the tree
		else if(x > root->val){
			root->right = insertNode(x,root->right);
		}
		return root;
	}

	// it will remove a node from BST
	TreeNode* removeNode(int x, TreeNode* root){
		TreeNode* temp;
		// if root is empty we can return null
		if(root==NULL)   return NULL;

		// if value is smaller than root then we will find it to the left of the tree
		else if(x<root->val){
			root->left = removeNode(x,root->left);
		}
		// if value is greater than root then we will find it to the right of the tree
		else if(x > root->val){
			root->right = removeNode(x,root->right);
		}

		//if the node to be deleted has both left child and right child 
		//find minimum node and copy it to the node which is to be deleted
	    
		else if(root->left && root ->right){
			temp = findMin(root->right);
			root->val = temp->val;
			root->right = removeNode(root->val,root->right);
		}

		// if node has either left or right child directly copy there data to root
		else
        {
            temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            delete temp;
        }

        return root;

	}

	// it find the minimum value on the left side of root
	 TreeNode* findMin(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        else if(root->left == NULL)
            return root;
        else
            return findMin(root->left);
    }

    // search a node in Tree using BST properties
  	bool searchNode(TreeNode* root, int target) {
        if(root == NULL)
            return NULL;
        else if(target==root->val) return true;
        else if(target < root->val)
            return searchNode(root->left, target);
        else if(target > root->val)
            return searchNode(root->right, target);
        else
            return false;
    }
    // Print the inorder traversal of the tree Left Root Right

    void inorder(TreeNode* root) {
        if(root == NULL)
            return;
        inorder(root->left);
        cout<<root->val << " ";
        inorder(root->right);
    }

    // it delete the memory that we assigned dynamically
    TreeNode* deallocate(TreeNode* root){
    	if(root==NULL) return NULL;
    	deallocate(root->left);
    	deallocate(root->right);
    	delete root;
    	return nullptr;
    }

// make the functions private makes the program follow OOPS concepts

public:
	// constructor
	BinarySearchTree(){
		root = NULL;
		cout<<"You can insert nodes in BST"<<"\n";
	}

	// destructor
	~BinarySearchTree(){
		root = deallocate(root);
	}

	// insert a node
	void insertNode(int val){
		root = insertNode(val,root);
		cout<<val<<" is inserted in the Tree"<<"\n";
	}

	// remove a node
	void removeNode(int val){
		root = removeNode(val,root);
		cout<<val<<" is removed from Tree"<<"\n";
	}

	// print the inorder traversal
	void printTree(){
		inorder(root);
		cout<<"\n";
	}

	void searchNode(int target){
		if(searchNode(root,target)){
			cout<<target<<" is present in Tree"<<"\n";
		}
		else{
			cout<<target<<" is not present in Tree"<<"\n";
		}
	}

};

// driver code
int main(){

	BinarySearchTree tree;
	tree.insertNode(10);
	tree.insertNode(9);
	tree.insertNode(20);
	tree.insertNode(7);
	tree.insertNode(11);
	tree.insertNode(19);
	tree.printTree();
	tree.searchNode(1);
	tree.removeNode(19);
	tree.printTree();

	return 0;
}