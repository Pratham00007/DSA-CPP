/*
Zig Zag Traversal Of Binary Tree


0

Problem Statement: Given a Binary Tree, print the zigzag traversal of the Binary Tree.
 Zigzag traversal of a binary tree is a way of visiting the nodes of the tree in a 
 zigzag pattern, alternating between left-to-right and right-to-left at each level.

Examples

Input:Binary Tree: 1 2 3 4 5 -1 6

Output: [[1],[3, 2],[4, 5, 6]]
Explanation: 

Level 1 (Root): Visit the root node 1 from left to right. Zigzag Traversal: [1]
Level 2: Visit nodes at this level in a right-to-left order. Zigzag Traversal:  [1], [3, 2]
Level 3: Visit nodes at this level in a left-to-right order. Zigzag Traversal: 
 [1], [3, 2], [4, 5, 6]

Input:
Binary Tree: 1 2 -1 4 5 -1 -1 7 8

Output :
 [[1], [2], [4, 5], [8, 7]]
Explanation: 
Level 1 (Root): Visit the root node 1 from left to right. Zigzag Traversal: [1]
Level 2: Visit nodes at this level in a right-to-left order. Zigzag Traversal:  [1], [2]
Level 3: Visit nodes at this level in a left-to-right order. Zigzag Traversal:  [1], [3, 2], [4, 5]
Level 4: Visit nodes at this level in a right-to-left order. Zigzag Traversal:  
[1], [3, 2], [4, 5], [8, 7]
*/

#include<bits/stdc++.h>
using namespace std;

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


    // Function to perform zigzag (spiral) level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>result;
        if(!root) return result;

        queue<TreeNode*>q;
        q.push(root);
        bool lefttoRight=true;

        while (!q.empty())
        {
            int size=q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
                TreeNode* node =q.front();
                q.pop();

                int index=lefttoRight ? i : size-i-1;

                level[index]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lefttoRight=!lefttoRight;
            result.push_back(level);
        }
        return result;
        
    }


int main(){

}