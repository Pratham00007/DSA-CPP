/*
Maximum Width of a Binary Tree


3

Problem Statement:
Given a Binary Tree, return its maximum width. The maximum width of a Binary Tree
 is the maximum diameter among all its levels. The width or diameter of a level 
 is the number of nodes between the leftmost and rightmost nodes.

Examples
Input: Binary Tree: 1 2 3 5 6 -1 9

Output: Maximum Width: 4
Explanation: 
Level 3 is the widest level of the Binary Tree and whose end-to-end width is 4 
comprising of nodes: {5, 6, null, 9}.

Input: Binary Tree: 1 2 3 5

Output: Maximum Width: 2
Explanation: 
Level 2 is the widest level of the Binary Tree and whose end-to-end width is 
comprised of nodes: {2, 3}.
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

int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxwidth=0;

        queue<pair<TreeNode*,int>>q;
         int maxWidth = 0;
        q.push({root,0});

       while (!q.empty()) {

            // Get the number of nodes at current level
            int size = q.size();

            // Store the index of the first node at this level
            int minIndex = q.front().second;

            // Initialize variables to track first and last index
            int first = 0;
            int last = 0;

            // Traverse all nodes at the current level
            for (int i = 0; i < size; i++) {

                // Get the current node and its relative index
                int currIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;

                // Pop the current node from the queue
                q.pop();

                // Update the first index if it's the first node
                if (i == 0)
                    first = currIndex;

                // Update the last index if it's the last node
                if (i == size - 1)
                    last = currIndex;

                // If left child exists, push it with calculated index
                if (node->left)
                    q.push({node->left, 2 * currIndex + 1});

                // If right child exists, push it with calculated index
                if (node->right)
                    q.push({node->right, 2 * currIndex + 2});
            }

            // Update the maximum width if needed
            maxWidth = max(maxWidth, last - first + 1);
        }

        // Return the result
        return maxWidth;

}