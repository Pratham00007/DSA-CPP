#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next= next;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* arr2ll(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;

    }
    return head;
}


bool sym=true;
Node* mid_node(Node* head){
    
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast!=nullptr) sym=false;
    return slow;
}

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

bool is_symm(Node* head1,Node* head2){
    Node*temp1=head1;
    Node*temp2=head2;
    while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->data!=temp2->data) return false;
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
    }
    return true;
}

int main(){
   
   vector<int>arr={1,2,3,3,2,1};
   Node* head=arr2ll(arr);
   
   Node* midi=mid_node(head);
   
   
   Node* reversed=reverse_ll(midi);
    cout<<sym<<endl;
    cout<<is_symm(head,reversed);


}