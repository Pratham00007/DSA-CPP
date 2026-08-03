/*
Construct A Binary Tree from Inorder and Preorder Traversal


1

Problem Statement: Given the Preorder and Inorder traversal of a Binary Tree, 
construct the Unique Binary Tree represented by them..

Examples
Input : preorder = [3, 9, 20, 15, 7] , inorder = [9, 3, 15, 20, 7]
Output : [3, 9, 20, null, null, 15, 7]
Explanation : The output tree is shown below.





Input : preorder = [3, 4, 5, 6, 2, 9] , inorder = [5, 4, 6, 3, 2, 9]
Output : [3, 4, 2, 5, 6, null, 9]
Explanation : The output tree is shown below.

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;

    }

    return build(preorder,0,preorder.size()-1, inorder , 0, inorder.size()-1,inMap);
}

TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){

                        if(preStart>preEnd || inStart>inEnd){
                            return nullptr;
                        }

                        TreeNode* root=new TreeNode(preorder[preStart]);
                        int inroot = inMap[root->val];
                        // to know no of elements in left subtree
                        int numsLeft=inroot-inStart;

                        root->left=build(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inroot-1,inMap);
                        root->right=build(preorder,preStart+numsLeft+1, preEnd,inorder,inroot+1, inEnd, inMap);

                        return root;


                    }