/*
Inorder successor and predecessor in BST
Subscribe to TUF+

Hints
Company
Given the root node of a binary search tree (BST) and an integer key.
 Return the Inorder predecessor and successor of the given key from the provided BST.



Note: key will always present in given BST.



If predecessor or successor is missing then return -1.


Example 1

Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 10

Output : [7, 12]

Explanation :



Example 2

Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 12

Output : [10, -1]

Explanation :
*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
}
};

TreeNode* inorderSucc(TreeNode* root,TreeNode* p){
    TreeNode* succes=NULL;
    while(root){
        if(p->val>=root->val) root=root->right;
        else{succes=root;root=root->left;}
    }
    return succes;
}