/*
Sort a Linked List


5

Problem Statement: Given a linked list, sort its nodes based on the data
 value in them. Return the head of the sorted linked list.

Examples
Input: 3->4->2->1->5 

Output: 1->2->3->4->5

Explanation: The input linked list when sorted from [3, 4, 2, 1, 5] results
 in a linked list with values [1, 2, 3, 4, 5].
Input: 40->20->60->10->50->30

Output: 10->20->30->40->50->60

Explanation: The input linked list when sorted from [40, 20, 60, 10, 50, 30]
 results in a linked list with values [10, 20, 30, 40, 50, 60].
*/


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


Node* findmid(Node* head){
    
    Node*slow=head;Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

Node* mergell(Node* list1, Node* list2){
    Node*dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while (list1!=NULL && list2!=NULL)
    {
        if(list1->data <list2->data){
            temp->next=list1;
            temp=list1;
            list1=list1->next;

        }else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;

        }
    }

    if(list1) temp->next=list1;
    else temp->next=list2;

    return dummyNode->next;
    
}

Node *sortLL(Node *head){
    if(head==NULL || head->next == NULL ) return head;

    Node* middle=findmid(head);
    Node* right=middle->next;
    middle->next=nullptr;
    Node* left=head;

    left =sortLL(left);
    right=sortLL(right);
    return mergell(left,right);
}