/*
Minimum time taken to BURN the Binary Tree from a Node


4

Problem Statement: Given a target node data and a root of binary tree. 
If the target is set on fire, determine the shortest amount of time needed 
to burn the entire binary tree. It is known that in 1 second all nodes
 connected to a given node get burned. That is its left child, right child, and parent.

Examples

Input : root = [1, 2, 3, 4, null, 5, 6, null, 7]. target = 1
Output : 3
Explanation :The node with value 1 is set on fire.
In 1st second it burns node 2 and node 3.
In 2nd second it burns nodes 4, 5, 6.
In 3rd second it burns node 7.



Input : root = [1, 2, 3, null, 5, null, 4], target = 4
Output : 4
Explanation : node with value 4 is set on fire.
In 1st second it burns node 3.
In 2nd second it burns node 1.
In 3rd second it burns node 2.
In 4th second it burns node 5.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minTime(TreeNode* root, int target) {
        // Create an undirected graph using adjacency list
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);

        // Use a set to track visited (burned) nodes
        unordered_set<int> visited;

        // Use queue for BFS starting from the target node
        queue<int> q;
        q.push(target);
        visited.insert(target);

        // Track time taken to burn the tree
        int time = 0;

        // Perform level-order BFS to simulate the spread of fire
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            // Process each node at the current level
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                // Traverse all adjacent (connected) nodes
                for (int neighbor : graph[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                        burned = true;
                    }
                }
            }

            // If fire spread to new nodes, increment time
            if (burned) time++;
        }

        // Return total time taken to burn the tree
        return time;
    }

    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
        // Base case: if node is null, return
        if (!node) return;

        // If parent exists, connect parent and node bidirectionally
        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        // Recursively connect left and right children
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }