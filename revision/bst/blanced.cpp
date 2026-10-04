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


int difheight(node*root){

    if (root==nullptr) return 0;
    int lefhei=difheight(root->left);
    if(lefhei==-1) return -1;
    int righheig=difheight(root->right);
    if(righheig==-1) return -1;

    if(abs(lefhei-righheig)>1) return -1;

    return max(lefhei,righheig)+1;
}


bool isbalenced(node*root){
    return difheight(root) !=-1;
}

int findheight(node*root,int &diameter){
    if(!root) return 0;
    int lh=findheight(root->left,diameter);
    int rh=findheight(root->right,diameter);
    diameter=max(lh+rh,diameter);
    return 1+max(lh,rh);
}

int diameter(node*root){
    int diameter=0;
    findheight(root,diameter);
    return diameter;
}



int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(5);
    root->left->right->right=new node(5);


    // preorder(root);
    cout<<diameter(root);
   
    
}