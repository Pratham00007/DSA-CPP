#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


  vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recc_trav(root,0,res);
        return res;
    }

    

void recc_trav(TreeNode* root, int level, vector<int>&res){
    if(root==NULL) return ;
    if(res.size()==level) res.push_back(root->val);
    recc_trav(root->right,level+1,res);
    recc_trav(root->left,level+1,res);
}



vector<int> leftSideView(TreeNode* root) {
    vector<int>res;
    recc2_trav(root,0,res);
    return res;
}

    

void recc2_trav(TreeNode* root, int level, vector<int>&res){
    if(root==NULL) return ;
    if(res.size()==level) res.push_back(root->val);
    recc_trav(root->left,level+1,res);
    recc_trav(root->right,level+1,res);
}



vector<int> bottomView(TreeNode* root){
    vector<int>ans;
    if(root==NULL) return ans;
    map<int,int>mpp;
    queue<pair<TreeNode*,int>>q;

    q.push({root,0});

    while(!q.empty()){
        auto it= q.front();
        q.pop();
        TreeNode* node=it.first;
        int line=it.second;

        mpp[line]=node->val;

        if(node->left != NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }

    for(auto it:mpp){
        ans.push_back(it.second);
    }

    return ans;


}




vector<int> topView(TreeNode* root) {
    vector<int>ans;

    if(root==NULL) return ans;

    map<int,int>mpp;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});

    while(!q.empty()){

            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->val;
            }

            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
}


vector<vector<int>>levelorder(TreeNode*root){
    vector<vector<int>>ans;
    if(root==nullptr) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode *node=q.front();
            q.pop();
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }

}
