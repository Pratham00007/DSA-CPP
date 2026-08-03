/*
Count Number of Nodes in a Binary Tree


1

Problem Statement: Given a Complete Binary Tree, count and return the number of nodes
 in the given tree. A Complete Binary Tree is a binary tree in which all levels 
 are completely filled, except possibly for the last level, and all nodes 
 are as left as possible.

Examples

Input: Binary Tree: 1 2 3 4 5 6


Output:
 6
Explanation: 
There are 6 nodes in this Binary Tree.

Input:
 Binary Tree: 2 4 3 5 9 8 7 1 6
Output :
 9
Explanation: 
There are 9 nodes in this Binary Tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize node with a value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    int lh=findLeftheight(root);
    int rh=findRightheight(root);

    // ie 2^h -1
    if(lh==rh) return (1<<lh)-1;

    return 1+countNodes(root->left)+countNodes(root->right);
}

int findLeftheight(TreeNode* node){
    int height=0;
    while(node){
        height++;
        node=node->left;
    }
    return height;
}

int findRightheight(TreeNode* node){
    int height=0;
    while(node){
        height++;
        node=node->right;
    }
    return height;
}



int main(){

}