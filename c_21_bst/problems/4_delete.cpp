/*
Delete a node in BST
Subscribe to TUF+

Hints
Company
Given the root node of a binary search tree (BST) and a value key.
 Return the root node of the BST after the deletion of the node with the given key value.



Note: As there can be many correct answers, the compiler returns true if the answer is correct, 
otherwise false.


Example 1

Input : root = [5, 3, 6, 2, 4, null, 7] , key = 3

Output : [5, 4, 6, 2, null, null, 7]

Explanation :

Below is image of the original BST


Below is image where the node 3 is deleted



Example 2

Input : root = [5, 3, 6, 2, 4, null, 7] , key = 0

Output : [5, 3, 6, 2, 4, null, 7]

Explanation :

The tree does not have node with value 0.
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

TreeNode* deleteNode(TreeNode* root,int key){
    if(root==NULL){
        return NULL;
    }if(root->val==key){
        // to get the value to be attached
        return helper(root);

    }
    TreeNode*dummy = root;
    while(root!=NULL){
        if(root->val >key){
            if(root->left!=NULL && root->left->val==key){
                root->left=helper(root->left);
                break;
            }else{
                root=root->left;
            }
        }else{
            if(root->right != NULL && root->right->val ==key){
                root->right=helper(root->right);
                break;
            }else{
                root=root->right;
            }
        }
    }
    return dummy;

}

TreeNode* helper(TreeNode* root){
    if(root->left==NULL){
        return root->right;
    }else if(root->right==NULL){
        return root->left;
    }
    TreeNode* rightChild=root->right;
    TreeNode* lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
TreeNode* findLastRight(TreeNode* root){
    if(root->right==NULL){
        return root;
    }
    return findLastRight(root->right);
}