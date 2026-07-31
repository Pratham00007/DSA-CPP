/*
Print all the Nodes at a distance of K in a Binary Tree


6

Problem Statement: Given the root of a binary tree, the value of a target node target, 
and an integer k. Return an array of the values of all nodes that have a distance k 
from the target node. The answer can be returned in any order (N represents null).

Examples
Input: 
root = [3, 5, 1, 6, 2, 0, 8, N, N, 7, 4] , target = 5, k = 2
Output:
[7,4,1]
Explanation:
 The nodes that are a distance 3 from the target node (with value 5) have values 7 , 4 and 1.
 

Input :
root = [3, 5, 1, 6, 2, 0, 8, N, N, 7, 4] , target = 5, k = 3
Output :
[0, 8]
Explanation :
 The nodes that are a distance 3 from the target node (with value 5) have values 0, 8.
 
*/

#include <bits/stdc++.h>
using namespace std;
// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*,TreeNode*>parentMap;
        mapParentNode(root,parentMap);
        return bfsFromTarget(target,parentMap,k);
}

void mapParentNode(TreeNode*root, unordered_map<TreeNode*,TreeNode*>&parentMap){
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();


        if(node->left) {
            parentMap[node->left]=node;
            q.push(node->left);
        }

        if(node->right) {
            parentMap[node->right]=node;
            q.push(node->right);
        }
        
    }
}


    vector<int> bfsFromTarget(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;

        q.push(target);
        visited.insert(target);

        int currentLevel=0;

        while(!q.empty()){
            int size=q.size();

            if(currentLevel++ ==k) break;

            for(int i=0;i<size;++i){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && visited.find(node->left)==visited.end()){
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && visited.find(node->right)==visited.end()){
                    visited.insert(node->right);
                    q.push(node->right);

                }

                if(parentMap.count(node) && visited.find(parentMap[node])==visited.end()){
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }

        }

        vector<int>result;
        while (!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
        
    }