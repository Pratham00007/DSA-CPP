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

// reverse ll

Node* reverse_ll(Node* head){
    Node* prevp=nullptr;
    Node*temp=head;
    Node*next_node=nullptr;
    while (temp)
    {
        next_node=temp->next;
        temp->next=prevp;
        prevp=temp;
        temp=next_node;
    }
    return prevp;
}

// palindrome check

bool is_palin(Node*head){
    // reverse from mid then check again reverse and return
    Node* slow=head;
    Node* fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*newhead=reverse_ll(slow->next);
    
    Node*temp1=head;
    Node*temp2=newhead;
    while(temp2){
        if(temp1->data!=temp2->data) {
            slow->next=reverse_ll(newhead);
            return false;
        }
        temp2=temp2->next;
        temp1=temp1->next;
    }
    slow->next=reverse_ll(newhead);
    return true;
}



int main(){
    vector<int>arr={1,2,1,2,1};
    Node*head=a2ll(arr);
    
//    insert_head(head,6);
    // traverse(reverse_ll(head));
    cout<<is_palin(head);

}
