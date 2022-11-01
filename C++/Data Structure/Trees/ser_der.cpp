/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*ptr=q.front(); q.pop();
            if(!ptr) s.append("#,");
            else s.append(to_string(ptr->val)+",");
            if(ptr){
                q.push(ptr->left);
                q.push(ptr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        string str;
        stringstream s(data);
        getline(s,str,',');
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*ptr=q.front(); q.pop();
            getline(s,str,',');
            if(str=="#"){
                ptr->left=NULL;
            }
            else{
                TreeNode*l=new TreeNode(stoi(str));
                ptr->left=l;
                q.push(l);
            }
            getline(s,str,',');
            if(str=="#"){
                ptr->right=NULL;
            }
            else{
                TreeNode*r=new TreeNode(stoi(str));
                ptr->right=r;
                q.push(r);
            }
        }
        return root;
    }
};

