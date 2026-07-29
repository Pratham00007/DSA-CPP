/*
Check for Symmetrical Binary Tree


Problem Statement: Given a Binary Tree, determine whether the given tree is symmetric or not.
 A Binary Tree would be Symmetric, when its mirror image is exactly the same as the original tree. 
 If we were to draw a vertical line through the centre of the tree, the nodes on the left and
  right side would be mirror images of each other.
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

bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return issymm(root->left,root->right);
    }

bool issymm(TreeNode* root1, TreeNode* root2){
    if(root1==NULL || root2==NULL){
        return root1==root2;
    }

    return (root1->val == root2->val) && issymm(root1->left,root2->right) && issymm(root1->right,root2->left);
}