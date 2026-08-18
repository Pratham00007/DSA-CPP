/*
Construct a BST from a preorder traversal
Subscribe to TUF+

Hints
Company
Given an array of integers preorder, which represents the preorder traversal 
of a BST (i.e., binary search tree), construct the tree and return its root.



It is guaranteed that it is always possible to find a binary search tree with 
the given requirements for the given test cases.



Note : As there can be many possible correct answers, the compiler outputs true
 if the solution is correct, else false.


Example 1

Input : preorder = [8, 5, 1, 7, 10, 12]

Output : [8, 5, 10, 1, 7, null, 12]

Explanation :

Below is the BST image



Example 2

Input : preorder = [1, 3]

Output : [1, null, 3]

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

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return build(preorder,i,INT_MAX);
}

TreeNode* build(vector<int>&A,int& i, int bound){
    if(i==A.size() || A[i]>bound ) return NULL;
    TreeNode*root = new TreeNode(A[i++]);
    root->left=build(A,i,root->val);
    root->right=build(A,i,bound);
    return root;
}

