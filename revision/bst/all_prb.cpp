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

bool isleaf(node*root){
    return (root!=nullptr && root->left==nullptr && root->right==nullptr);
}

void addleft(node*root,vector<int>&ans){
    node*curr=root->left;
    while(curr){
        if (!isleaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addright(node*root,vector<int>&ans){
    node* curr=root->right;
    vector<int>temp;
    while(curr){
        if(!isleaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>-1;i--) ans.push_back(temp[i]);
}

void addleaf(node*root,vector<int>&ans){
    if(isleaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if(root->left)addleaf(root->left,ans);
    if(root->right) addleaf(root->right,ans);
}

vector<int>clctrav(node*root){
    vector<int>clk;
    if(!root) return clk;
    if(!isleaf(root))clk.push_back(root->data);
    addleft(root,clk);
    addleaf(root,clk);
    addright(root,clk);
    return clk;
}


vector<int>top_vew(node*root){
    vector<int>ans;
    if(root==nullptr) return ans;
    map<int,int>mpp;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int cordinate=it.second;
        node* add=it.first;
        if(mpp.find(cordinate)==mpp.end()) mpp[cordinate]=add->data;

        if(add->left) q.push({add->left,cordinate-1});
        if(add->right) q.push({add->right,cordinate+1});
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

void right_rec(node* root,int level,vector<int>&ans){
    if(root==nullptr) return;
    if(level==ans.size()) ans.push_back(root->data);
    if(root->right) right_rec(root->right,level+1,ans);
    if(root->left) right_rec(root->left,level+1,ans);
}

vector<int>right_view(node*root){
    vector<int>ans;
    int level=0;
    right_rec(root,level,ans);
    return ans;
}

// check symmetric


bool sym_help(node*left,node*right){
    if(left==nullptr || right==nullptr) return left==right;
    if(left->data!=right->data) return false;
    return sym_help(left->left,right->right) &&  sym_help(left->right,right->left);
}

bool issymm(node*root){
    return sym_help(root->left,root->right);
}


node* insert_node(node*root1,int val){
    if(root1==nullptr) {
        return new node(val);
    }
    node* root=root1;
    while (true)
    {
        if(root->data<=val){
            if(root->right!=nullptr)root=root->right;
            else{
                root->right=new node(val);
                break;
            }
        }
        else{
            if(root->left!=nullptr)root=root->left;
            else{
                root->left=new node(val);
                break;
            }
        }
    }
    return root1;
    
}

void preorder(node* root){
    if(root==nullptr) return ;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct node*root=new node(5);
    root->left=new node(3);

    root->right=new node(7);
    root->left->right=new node(4);
    
    root->right->left=new node(6);
    // root->left->right->right=new node(5);

    // vector<int>anse=right_view(root);
    // for(int i=0;i<anse.size();i++){
    //     cout<<anse[i]<<" ";
    // }

    root=insert_node(root,0);
    
    preorder(root);
   
    
}