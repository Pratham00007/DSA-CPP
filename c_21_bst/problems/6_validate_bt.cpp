/*
Given the root node of a binary tree. Return true if the given binary tree is a
  binary search tree(BST) else false.



A valid BST is defined as follows:



The left subtree of a node contains only nodes with key strictly less than the node's key.


The right subtree of a node contains only nodes with key strictly greater than the node's key.


Both the left and right subtrees must also be binary search trees.

Example 1

Input : root = [5, 3, 6, 2, 4, null, 7]

Output : true

Explanation :

Below is image of the given tree.



Example 2

Input : root = [5, 3, 6, 4, 2, null, 7]

Output : false

Explanation :

﻿Below is image of the given tree.

The node 4 and node 2 violates the BST rule of smaller to left and larger to right.
*/


#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
}
};

    bool isValidBST(TreeNode* root) {
        return isval(root,INT_MIN, INT_MAX);
    }

    bool isval(TreeNode * root, long minval,long maxval){
        if(root==NULL) return true;
        if(root->val>= maxval || root->val<=minval) return false;
        return isval(root->left,minval,root->val) && isval(root->right,root->val,maxval);
    }