/*
Print Root to Node Path in a Binary Tree


4

Problem Statement: Given a Binary Tree and a reference to a root belonging to it. 
Return the path from the root node to the given leaf node.
Note: No two nodes in the tree have the same data value and it is assured that the 
given node is present and a path always exists.

Examples
Input: Binary Tree: 1 2 3 4 5 -1 -1 -1 -1, Node: 7

Output: [1, 2, 5, 7] 
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    // Value of the node
    int val;

    // Pointers to left and right children
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool getPath(TreeNode* root, vector<int>& arr, int x) {
    if(!root) return false;

    arr.push_back(root->val);

    if(root->val==x) return true;

    if (getPath(root->left,arr,x) || getPath(root->right,arr,x)) return true;

    arr.pop_back();
    return false;

}


 vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;

        if (A == NULL) {
            return arr;
        }

        getPath(A, arr, B);

        return arr;
    }

int main(){

}