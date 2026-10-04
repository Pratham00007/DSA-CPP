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

node* build(vector<int>&arr,int &i,int ub){
    if(arr[i]>ub || i==arr.size()) return nullptr;

    node* newnode=new node(arr[i++]);
    newnode->left=build(arr,i,newnode->data);
    newnode->right=build(arr,i,ub);
    return newnode;

}

node* build_preorder(vector<int>arr){
    int i=0;
    return build(arr,i,INT_MAX);
}

void preorder(node* root){
    if(root==nullptr) return ;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int>arr={8,5,1,7,10,12};
    preorder(build_preorder(arr));
}