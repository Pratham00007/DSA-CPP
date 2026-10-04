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




int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(5);
    root->left->right->right=new node(5);


    // preorder(root);
    // cout<<diameter(root);
   
    
}