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

int cnt(Node*head){
    Node* temp=head;
    int cnt=0;
    while(temp){
        
        temp=temp->next;
        cnt++;

    }
 return cnt;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node*head=a2ll(arr);
    int ans=cnt(head);
    cout<<ans;

}
