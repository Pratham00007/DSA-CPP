/*
Construct Binary Tree from Inorder and PostOrder Traversal


0

Problem Statement: Given the Postorder and Inorder traversal of a Binary Tree,
 construct the Unique Binary Tree represented by them.

Examples
Example :
Input: Inorder: [ 40, 20 , 50, 10, 60, 30], Postorder: [40, 50, 20, 60, 30, 10]




Explanation:  The unique Binary Tree hence created has inorder traversal: 
[40, 20, 50, 10, 60, 30] and postorder traversal: [40, 50, 20, 60, 30, 10].
                                      
Example :
Input: Inorder: [9, 3, 15, 20, 7], Postorder: [9, 15, 7, 20, 3]




Explanation:  The unique Binary Tree hence created has inorder traversal:
 [9, 3, 15, 20, 7] and postorder traversal: [9, 15, 7, 20, 3].	
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     if(inorder.size() != postorder.size()) return nullptr;

     map<int,int>hm;
     for(int i=0;i<inorder.size();i++){
        hm[inorder[i]]=i;
     }

     return build(inorder,0,inorder.size()-1, postorder,0,postorder.size()-1,hm);
}

TreeNode* build(vector<int>&inorder,int is,int ie,
     vector<int>postorder, int ps, int pe , map<int,int>&hm){

        if(ps>pe || is>ie){
            return nullptr;
        }

        TreeNode* root=new TreeNode(postorder[pe]);

        int inRoot= hm[postorder[pe]];
        int numsLeft=inRoot-is;

        root->left=build(inorder,is,inRoot-1, postorder,ps, ps+numsLeft-1, hm);
        root->right=build(inorder,inRoot+1, ie, postorder,ps+numsLeft,pe-1,hm);


        return root;

}



int main(){

}