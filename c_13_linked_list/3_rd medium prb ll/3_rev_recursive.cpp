
#include<bits/stdc++.h>
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

Node* reversell(Node *head){
    if (head==NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reversell(head->next);
    Node* front =head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}