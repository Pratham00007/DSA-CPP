/*
Check if two trees are identical


2

Problem Statement: Given two Binary Trees, return if true if the two trees are identical, 
otherwise return false..

Two trees are said to be identical if these three conditions are met for every pair of nodes :

Value of a node in the first tree is equal to the value of the corresponding node in the 
second tree.
Left subtree of this node is identical to the left subtree of the corresponding node.
Right subtree of this node is identical to the right subtree of the corresponding node.
Examples
Example 1:
Input:Binary Tree 1: 1 2 3 -1 -1 4 5, Binary Tree 2: 1 2 3 -1 -1 4 5



Output: True, these trees are identical.

Example 2:
Input:Binary Tree 1: 1 2 3 -1 -1 4 5, Binary Tree 2: 1 2 3 -1 -1 4



Output :  False, these trees are not identical.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;       // Data stored in the node
    TreeNode* left;     // Pointer to the left child
    TreeNode* right;    // Pointer to the right child

    // Constructor to initialize the node with a value
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return (p==q);

        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }


int main(){

}