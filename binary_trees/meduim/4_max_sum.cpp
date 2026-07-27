/*
Maximum Sum Path in Binary Tree


3

Problem Statement:
Given a Binary Tree, determine the maximum sum achievable along any path within the tree.
 A path in a binary tree is defined as a sequence of nodes where each pair of adjacent nodes
  is connected by an edge. Nodes can only appear once in the sequence, and the path is not 
  required to start from the root. Identify and compute the maximum sum possible along 
  any path within the given binary tree.

Examples
Input: Binary Tree: -10 9 20 -1 -1 15 7

Output: 42
Explanation: 
Out of all the paths possible in the Binary Tree, 15 -> 20 -> 7 has the greatest sum ie. 42.

Input: Binary Tree: -2 2 1

Output: 2
Explanation: 
Out of all the paths possible in the Binary Tree, a path starting and ending at the node 
with value 2 has the greatest sum ie. 2.
*/


#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Tree Node Definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};



int maxPathSum(TreeNode* root) {
    int maxsum=INT_MIN;
    dfs(root,maxsum);
    return maxsum;
}

int dfs(TreeNode* root, int &maxSum){
    if (root==NULL) return 0;

    int left=max(0,dfs(root->left,maxSum));
    int right=max(0,dfs(root->right,maxSum));
    maxSum=max(maxSum,left+right+root->val);

    return max(left,right)+root->val;
}

int main(){

}