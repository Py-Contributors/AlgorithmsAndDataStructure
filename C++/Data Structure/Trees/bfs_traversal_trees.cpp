/*
              8
            /  \
          10    3
         / \     \
        1   6     14
           / \    /
          9   7  13
          input->8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
*/


#include <bits/stdc++.h>
using namespace std;

class node {
  public:
  int data;
  node* left;
  node* right;

  node(int data) {
    this->data = data;
  }
};

node* buildTree() {
  int d;
  cin >> d;
  node* n = new node(d);
  if(d == -1) {
    return NULL;
  }
  n->left = buildTree();
  n->right = buildTree();

  return n;
}

int height(node* root) {
  if(root == NULL) {
    return 0;
  }
  int leftSubtree = height(root->left);
  int rightSubtree = height(root->right);

  return max(leftSubtree, rightSubtree) + 1;
}
void printTree(node* root) {
  if(root == NULL) {
    return;
  }

  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right); 
}

void printKthLevel(node* root, int k) {
  if(root == NULL) {
    return;
  }
  if(k == 0)  return;
  if(k == 1) {
    cout << root->data << " ";
  }
  printKthLevel(root->left, k-1);
  printKthLevel(root->right, k-1);

}

void printAllLevels(node* root) {
  int H = height(root);

  for(int i=0;i<H;i++) {
    printKthLevel(root, i);
    cout << endl;
  }
}

void bfs(node* root) {
  queue<node*> q;
  q.push(root);

  while(!q.empty()) {
    node* f = q.front();
    cout << f->data << " ";
    q.pop();

    if(f->left) {
      q.push(f->left);
    }
    if(f->right) {
      q.push(f->right);
    }
  }

}
int  main() {

  node* root = buildTree();
  printTree(root);
  cout << endl << height(root) << endl;
  printKthLevel(root, 3);

  cout << endl;
  printAllLevels(root);

  cout << endl;
  bfs(root);
  return 0;
}
