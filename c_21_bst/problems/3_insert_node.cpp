/*
Insert a Given Node in Binary Search Tree


0

Problem Statement: Given the root node of a binary search tree (BST) and a
 value val to insert into the tree. Return the root node of the BST after the insertion.

It is guaranteed that the new value does not exist in the original BST. 
Note that the compiler output shows true if the node is added correctly, else false.

Examples
Input: root = [4, 2, 7, 1, 3] , val = 5
Output: [4, 2, 7, 1, 3, 5]
Explanation: Below is image where the node 5 is inserted


Input: root = [40, 20, 60, 10, 30, 50, 70] , val = 25]
Output: [40, 20, 60, 10, 30, 50, 70, null, null, 25]
Explanation: Below is image where the node 25 is inserted

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*cr=root;
        
        if(root==NULL) return new TreeNode(val);
        while(true){

            if(cr->val<=val){
                if(cr->right != NULL) cr=cr->right;
                else{ cr->right=new TreeNode(val);break;}
            }else{
                if(cr->left!=NULL) cr=cr->left;
                else{
                    cr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
}



};

