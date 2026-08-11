/*
Serialize And Deserialize a Binary Tree


1

Problem Statement: Given a Binary Tree, design an algorithm to serialise and deserialise it. 
There is no restriction on how the serialisation and deserialization takes place. 
But it needs to be ensured that the serialised binary tree can be deserialized to 
the original tree structure. Serialisation is the process of translating a data 
structure or object state into a format that can be stored or transmitted
 (for example, across a computer network) and reconstructed later. 
 The opposite operation, that is, extracting a data structure from 
 stored information, is deserialization.

Examples
Input:Binary Tree: 1 2 3 -1 -1 4 5


Output:
After Serialisation: 1,2,3,#,#,4,5,#,#,#,#, After Deserialization: (Original Tree Back)		
Explanation: 
 Any algorithm that compresses this binary tree to a string which can be transmitted and 
 from which the binary tree can be reconstructed later can be used.
Here we have used a serialisation algorithm based on level order traversal where comma
 separates the nodes and # denotes null nodes.



Input:
Binary Tree: 1 2 3 -1 4 5 -1

Output :
After Serialisation: 1,2,3,#,4,5,#, After Deserialization: (Original Tree Back)
Explanation: 
 Any algorithm that compresses this binary tree to a string which can be transmitted 
 and from which the binary tree can be reconstructed later can be used.
Here we have used a serialisation algorithm based on level order traversal where comma
 separates the nodes and # denotes null nodes.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize node value and child pointers
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};





int main(){

}