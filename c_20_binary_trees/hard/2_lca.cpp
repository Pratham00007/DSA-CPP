/*
Lowest Common Ancestor for two given Nodes


2

Problem Statement: Given a root of binary tree, find the lowest common ancestor (LCA) of
 two given nodes (p, q) in the tree.

The lowest common ancestor is defined between two nodes p and q as the lowest node in 
T that has both p and q as descendants (where we allow a node to be a descendant of itself).

Examples
Example 1:
Input:
 root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1  
Output:
 3  
Explanation:
 The lowest common ancestor (LCA) of nodes 5 and 1 is node 3, as it is the first common ancestor
  of both nodes in the binary tree.

Example 2:
Input:
 root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4  
Output:
 5  
Explanation:
 The lowest common ancestor (LCA) of nodes 5 and 4 is node 5, as node 5 is the ancestor of
  node 4 in the binary tree.
*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    // Value of the node
    int val;

    // Pointers to left and right children
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);

        if(left==NULL) return right;
        else if(right==NULL) return left;

        else return root;

}