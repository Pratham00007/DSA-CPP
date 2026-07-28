/*
Vertical Order Traversal of Binary Tree

Problem Statement: Given a Binary Tree, return the Vertical Order Traversal of it starting
 from the Leftmost level to the Rightmost level. If there are multiple nodes passing through
  a vertical line, then they should be printed as they appear in level order traversal of the tree.

Examples

Input:Binary Tree: 1 2 3 4 10 9 11 -1 5 -1 -1 -1 -1 -1 -1 -1 6

Output: Vertical Order Traversal: [[4],[2, 5], [1, 10, 9, 6],[3],[11]]
Explanation: Vertical Levels from left to right:Level -2: [4],Level -1: [2],Level 0:
 [1, 10, 9, 6] (Overlapping nodes are added in their level order sequence),Level 1: 
 [3],Level 2: [11],

Input:Binary Tree: 2 7 5 2 6 -1 9 -1 -1 5 11 4 -1

Output : [[2],[7, 5],[2, 6], [5, 11, 4],[9]]
Explanation: Vertical Levels from left to right:Level -2: [2],Level -1: [7, 5],Level 0:
 [2, 6],Level 1: [5, 11, 4] (Overlapping nodes are added in their level order sequence),
 Level 2: [9].
*/

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a binary tree node
struct Node {
    // This stores the value of the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;

    // Constructor initializes node with value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// This class contains the solution logic
class Solution {
public:
    // Function to perform vertical order traversal
    vector<vector<int>> findVertical(Node* root) {
        // A map is used to store nodes grouped by vertical and level
        map<int, map<int, multiset<int>>> nodes;

        // A queue is used for BFS, storing node and its coordinates
        queue<pair<Node*, pair<int, int>>> todo;

        // Push the root node with vertical = 0 and level = 0
        todo.push({root, {0, 0}});

        // Perform BFS traversal
        while (!todo.empty()) {
            // Get the front element in queue
            auto p = todo.front();
            todo.pop();

            // Extract node
            Node* temp = p.first;
            // Extract vertical (x)
            int x = p.second.first;
            // Extract level (y)
            int y = p.second.second;

            // Insert the node into map by vertical and level
            nodes[x][y].insert(temp->data);

            // If left child exists, push with updated coordinates
            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            // If right child exists, push with updated coordinates
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        // Final answer vector
        vector<vector<int>> ans;

        // Iterate through verticals in map
        for (auto p : nodes) {
            vector<int> col;
            // Collect all nodes in order of levels
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Push the column into result
            ans.push_back(col);
        }

        // Return final vertical order traversal
        return ans;
    }
};
