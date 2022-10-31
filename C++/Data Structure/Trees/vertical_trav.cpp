/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map<vert,map<level,level vals>>
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q; // node val, vert level;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto a=q.front(); // 3,0,0
            q.pop();
            TreeNode*ptr=a.first;
            int vert=a.second.first,lev=a.second.second;
            mp[vert][lev].insert(ptr->val);
            if(ptr->left) q.push({ptr->left,{vert-1,lev+1}});
            if(ptr->right) q.push({ptr->right,{vert+1,lev+1}});
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            vector<int>v;
            for(auto p:i.second){ // here i.second is int,multiset
                // insert(pos,start and begin of another ds)
                v.insert(v.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};