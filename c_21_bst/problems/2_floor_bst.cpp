/*
Floor in a Binary Search Tree


1

Problem Statement: Given a Binary Search Tree and a key, return the floor of the given key in the 
Binary Search Tree.
Floor of a value refers to the value of the largest node in the Binary Search Tree that is 
smaller than or equal to the given key. If the floor node does not exist, return nullptr.

Examples
Input : Binary Search Tree: 10 5 15 2 6 -1 -1, Key = 7

Output : 6
Explanation :  In the given BST, the largest value smaller or equal to 7 is 6. 
Input : Binary Search Tree: 8 5 12 4 7 10 14 -1 -1 6 -1 -1 -1 13, Key = 9

Output : 8
Explanation : In the given BST, the largest value smaller or equal to 9 is 8. 
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


int floorBST(TreeNode* root,int key){
    int floor=-1;
    while(root){
        if(root->val==key) {
            floor=key;
            return key;
        }
        if(key>root->val){
            floor=root->val;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
}


};

