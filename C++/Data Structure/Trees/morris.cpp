/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        Node*cur=root;
        vector<int>v;
        //code here
        while(cur){
            if(!cur->left) {v.push_back(cur->data); cur=cur->right;}
            else{
                Node*pred=cur->left;
                while(pred->right and pred->right!=cur) pred=pred->right;
                if(!pred->right){
                    pred->right=cur;
                    cur=cur->left;
                }
                else{
                    pred->right=NULL;
                    v.push_back(cur->data);
                    cur=cur->right;
                }
                
            }
        }
        return v;
    }
};