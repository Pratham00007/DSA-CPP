/*
Boundary Traversal of a Binary Tree


4

Boundary Traversal of a Binary Tree .

Problem Statement: Given a Binary Tree, perform the boundary traversal of the tree. The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.

Examples
Example 1:
Input:Binary Tree: 1 2 7 3 -1 -1 8 -1 4 9 -1 5 6 10 11



Output: Boundary Traversal: [1, 2, 3, 4, 5, 6, 10, 11, 9, 8, 7]
Explanation: The boundary traversal of a binary tree involves visiting its boundary nodes in an anticlockwise direction:
Starting from the root, we traverse from: 1

The left side traversal includes the nodes: 2, 3, 4

The bottom traversal include the leaf nodes: 5, 6, 10, 11

The right side traversal includes the nodes: 9, 8, 7

We return to the  root and the boundary traversal is complete.






Example-2
Input:Binary Tree: 10 5 20 3 8 18 25 -1 7 -1 -1



Output : Boundary Traversal: [10, 5, 3, 7, 8, 18, 25, 20]
Explanation: The boundary traversal of a binary tree involves visiting its 
boundary nodes in an anticlockwise direction:
Starting from the root, we traverse from: 10

The left side traversal includes the nodes: 5

The bottom traversal include the leaf nodes: 3, 7, 8, 18, 25

The right side traversal includes the nodes: 20

We return to the  root and the boundary traversal is complete.
*/


#include <bits/stdc++.h>
using namespace std;

// Structure to represent a binary tree node
struct TreeNode {
    int val;                // Value of the node
    TreeNode* left;         // Pointer to left child
    TreeNode* right;        // Pointer to right child
    // Constructor to initialize node with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isleaf(TreeNode* root){
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode* root, vector<int>&res){
    TreeNode* curr=root->left;
    while (curr)
    {
        if(isleaf(curr)){
            res.push_back(curr->val);
        }

        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
    
}

void addRightBound(TreeNode* root, vector<int>&res){
    TreeNode* curr=root->right;
    vector<int>temp;
    while(curr){
        if(!isleaf(curr)){
            temp.push_back(curr->val);
        }
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>-1;i--){
        res.push_back(temp[i]);
    }
}

void addleaf(TreeNode* root, vector<int>&res){
    if (isleaf(root)) {
        res.push_back(root->val);
        return ;
    }

    if(root->left){
        addleaf(root->left,res);
    }
    if(root->right){addleaf(root->right,res);}
}

vector<int> printBoundary(TreeNode* root) {

    vector<int>res;
    if(!root) return res;

    if(!isleaf(root)) res.push_back(root->val);
    addLeftBoundary(root,res);
    addleaf(root,res);
    addRightBound(root,res);

    return res;

}