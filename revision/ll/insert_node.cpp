#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};


Node* a2ll(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void traverse(Node*head){
    Node* temp=head;
    while(temp){
    cout<<temp->data;
    temp=temp->next;
   }
}

void insert_head(Node*&head,int val){
    Node* newnode=new Node(val);
    newnode->next=head;
    head=newnode;
    
}

void insert_tail(Node*&head,int val){
    Node* newnode=new Node(val);
    
    if(head == nullptr) {head=newnode;return ;}

    Node*temp=head;
    while(temp->next){
        temp=temp->next;
    }    
    temp->next=newnode;
}

int main(){
    vector<int>arr={};
    Node*head=a2ll(arr);
    
//    insert_head(head,6);
insert_tail(head,6);
    traverse(head);

}
