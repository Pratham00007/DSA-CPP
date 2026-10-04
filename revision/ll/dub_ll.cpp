#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*next;
    node*prev;

    node(int data1,node* next1,node*prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

node* arr2dll(vector<int>arr){
    node *newnode=new node(arr[0]);
    node* prev_node=newnode;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        prev_node->next=temp;
        temp->next=nullptr;
        temp->prev=prev_node;
        prev_node=temp;
    }
    return newnode;

}

void traverse(node*head){
    node*temp=head;
    node*tail=head;
    while(temp){
        cout<<temp->data;
        tail=temp;
        temp=temp->next;
    }
    cout<<endl;
    while(tail){
        cout<<tail->data;
        tail=tail->prev;
    }
}

void del_head(node* &head){
    node*temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
}

void del_tail(node*head){
    node*temp=head;
    while(temp->next->next){
       
        temp=temp->next;
    }
     node * delnode=temp->next;
     temp->next=nullptr;
     delete delnode;
}

node* reverse_dll(node*&head){
    node* prev0=nullptr;
    node* curr=head;

    while(curr!=nullptr){
        prev0=curr->prev;
        curr->prev=curr->next;
        curr->next=prev0;
        curr=curr->prev;
    }
    return prev0->prev;

}

int main(){
    vector<int>arr={1,2,3,4,5};
    node*head=arr2dll(arr);
    
//    insert_head(head,6);
    // insert_tail(head,6);
    reverse_dll(head);
    traverse(head);

}

