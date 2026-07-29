/*
Top view of a Binary Tree


4

Problem Statement: Given a Binary Tree, return its Top View. The Top View of a 
Binary Tree is the set of nodes visible when we see the tree from the top.

Examples

Input:Binary Tree: 1 2 3 4 10 9 11 -1 5 -1 -1 -1 -1 -1 -1 -1 6

Output: Top View: [4, 2, 1, 3, 11]
Explanation: 

Input:Binary Tree: 2 7 5 2 6 -1 9 -1 -1 5 11 4 -1

Output : Top View: [2, 7, 2, 5, 9]
Explanation: 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    // Value stored in the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;
    // Constructor to initialize a node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


vector<int> topView(Node* root) {
    vector<int>ans;

    if(root==NULL) return ans;

    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty()){

       // Extract the front element of the queue
            auto it = q.front();
            q.pop();

            // Get the node and its vertical position
            Node* node = it.first;
            int line = it.second;

            // If this vertical position is being visited for the first time, store it
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            // If there is a left child, push it with vertical level - 1
            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            // If there is a right child, push it with vertical level + 1
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Traverse the map and store values in the answer vector
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        // Return the result
        return ans;
}

int main(){

}