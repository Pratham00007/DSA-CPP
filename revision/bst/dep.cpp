#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data1){
        data=data1;
        left=right=nullptr;
    }
};

void preorder(node* root){
    if(root==nullptr) return ;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}


// bfs

vector<vector<int>>bfs(node*root){
    vector<vector<int>>ans;
    if(root==nullptr) return ans;
    queue<node*>q;
    q.push(root);
    while (!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node* newnode= q.front();
            q.pop();
            if(newnode->left!=nullptr) q.push(newnode->left);
            if(newnode->right!=nullptr) q.push(newnode->right);
            level.push_back(newnode->data);
        }
        ans.push_back(level);
    }
    return ans;   

}

int maxdepth(node*root){
    if(root==nullptr) return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);

    return 1+max(lh,rh);
}



int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(5);

    // preorder(root);
    cout<<maxdepth(root);
   
    
}