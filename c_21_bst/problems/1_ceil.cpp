
#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

int findceil(TreeNode*root,int key){
 int ceil=-1;
 while(root){
    if(root->val==key){
        ceil=root->val;
        return ceil;
    }

    if(key>root->val){
        root=root->right;
    }else{
        ceil=root->val;
        root=root->left;
    }
 }
 return ceil;
}