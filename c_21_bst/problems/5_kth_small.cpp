/*
Kth largest/smallest element in Binary Search Tree


3

Problem Statement: Given the root node of a binary search tree (BST) and an integer k.
Return the kth smallest and largest value (1-indexed) of all values of the nodes in the tree.

Return the 1st integer as kth smallest and 2nd integer as kth largest in the returned array.

Examples
Example 1:
Input:
 root = [3, 1, 4, null, 2], k = 1  
Output:
 [1, 4]  
Explanation:
 
The 1st smallest value in the given BST is 1.  
The 1st largest value in the given BST is 4.

Example 2:
Input:
 root = [5, 3, 6, 2, null, null, null, 1], k = 3  
Output:
 [3, 3]  
Explanation:
  
The 3rd smallest value in the given BST is 3.  
The 3rd largest value in the given BST is 3.
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
class Solution{
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        inorder(root);
        return result;


    }

private:
int k;
int result;

void inorder(TreeNode* node){
    if(node) {
        inorder(node->left);
        if(--k==0){
            result=node->val;
            return;

        }
        inorder(node->right);
    }
}


};