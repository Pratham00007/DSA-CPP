/*
Calculate the Diameter of a Binary Tree


Problem Statement: Given the root of the Binary Tree, return the length of its diameter. 
The Diameter of a Binary Tree is the longest distance between any two nodes of that tree.
 This path may or may not pass through the root.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node* root, int diameter){
    if(root==NULL) return ;
    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);

    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);

}
  int diameterOfBinaryTree(Node* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }

int main(){

}