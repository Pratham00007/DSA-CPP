/*
Largest BST in Binary Tree
Subscribe to TUF+

Hints
Company
Given a root of Binary Tree, where the nodes have integer values. Return the size of the
 largest subtree of the binary tree which is also a BST.



A binary search tree (BST) is a binary tree data structure which has the following properties.



The left subtree of a node contains only nodes with data less than the node’s data.


The right subtree of a node contains only nodes with data greater than the node’s data.


Both the left and right subtrees must also be binary search trees.

Example 1

Input : root = [2, 1, 3]

Output : 3

Explanation :

The given complete binary tree is a BST consisting of 3 nodes.



Example 2

Input : root = [10, null, 20, null, 30, null, 40, null, 50]

Output : 5

Explanation :

If we consider the node 10 as root node then it forms the largest BST.
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

