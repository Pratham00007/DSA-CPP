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

bool presen(Node*head,int val){
    Node* temp=head;
    
    while(temp){
        if(temp->data==val) return true;
        temp=temp->next;
       

    }
 return false;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node*head=a2ll(arr);
    
    cout<<presen(head,-5);

}
