#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    // comnnstructor
    Node(int data1,Node* next1){
        data=data1;;
        next=next1;

    }

    // 2nd constructor to avoid passing null in pointer wen nothing ahead

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

};

Node* convertLL(vector<int>arr){
    // will return head
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int main(){
vector<int>arr={1,2,3,4};
Node* head=convertLL(arr);

// traversal
Node*temp=head;
while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
}
}