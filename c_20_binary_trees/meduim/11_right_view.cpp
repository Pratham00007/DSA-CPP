/*
Right/Left view of binary tree


2

Problem Statement: Assuming standing on the right side of a binary tree 
and given its root, return the values of the nodes visible, arranged from top to bottom.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


  vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recc_trav(root,0,res);
        return res;
    }

void recc_trav(TreeNode* root, int level, vector<int>&res){
    if(root==NULL) return ;
    if(res.size()==level) res.push_back(root->val);
    recc_trav(root->right,level+1,res);
    recc_trav(root->left,level+1,res);
}