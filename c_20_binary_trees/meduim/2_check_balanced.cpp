/*
Check if the Binary Tree is Balanced Binary Tree

Problem Statement: Given a Binary Tree, return true if it is a Balanced Binary Tree
 else return false. A Binary Tree is balanced if, for all nodes in the tree, 
 the difference between left and right subtree height is not more than 1..

Examples
Example 1:
Input : [3, 9, 20, null, null, 15, 7]


Output : Yes

Example 2:
Input : [1, 2, null, null, 3]


Output : No


*/

/*
Maximum depth of a Binary Tree


4

Problem Statement:
Given the root of a Binary Tree, return the height of the tree. 
The height of the tree is equal to the number of nodes on the longest path
 from root to a leaf.

Examples
Input: Binary Tree: 1 2 5 -1 -1 4 6 5

Output: 4
Explanation: 
In the above example, the height of the binary tree is along the longest path
 from the root node 1 -> 5 -> 4 -> 5. 

Input: Binary Tree: 3 1 2
Output: 2
Explanation: 
We traverse the binary tree in the order of Left, RIght then Root recursively
 resulting in the following traversal:
*/
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    // Function to find the
    // maximum depth of a binary tree
    int maxDepth(Node* root){
        // If the root is NULL
        // (empty tree), depth is 0
        if(root == NULL){
            return 0;
        }
        
        // Recursive call to find the
        // maximum depth of the left subtree
        int lh = maxDepth(root->left);
        
        // Recursive call to find the
        // maximum depth of the right subtree
        int rh = maxDepth(root->right);
        
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        // Return the maximum depth of the
        // tree, adding 1 for the current node
        return 1 + max(lh, rh);
    }
};

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    

    Solution solution;
    int depth = solution.maxDepth(root);
    if(depth==-1) cout<<"Unbalanced";
    else cout<<"balanced";


    return 0;
}
                            