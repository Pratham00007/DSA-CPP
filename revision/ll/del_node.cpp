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

Node* remove_head(Node* head){
    if(!head) return head;
    Node*temp=head;
    head=head->next;
    
    delete temp;
    return head;
}

void remove_tail(Node*head){
    if(head==nullptr || head->next==nullptr) head=nullptr;
    Node* temp=head;
    while(temp->next->next){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
}

void traverse(Node*head){
    Node* temp=head;
    while(temp){
    cout<<temp->data;
    temp=temp->next;
   }
}


void delkth(Node*&head,int k){
    Node*temp=head;
    int cnt=1;
    if(k==1){
        Node* tedel=head;
        head=head->next;
        delete tedel;
        return ;
    }
    while(temp && cnt!=k-1){
        temp=temp->next;
        cnt++;
    }
    Node* todel=temp->next;
    temp->next=temp->next->next;
    delete todel;

}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node*head=a2ll(arr);
    
    // cout<<remove_head(head)->data;
    // remove_tail(head);
    delkth(head,5);
    traverse(head);

}
