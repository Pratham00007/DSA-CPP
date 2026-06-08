/*
Reverse Linked List in groups of Size K


4

Problem Statement: Given the head of a singly linked list containing integers,
 reverse the nodes of the list in groups of k and return the head of the modified list.
  If the number of nodes is not a multiple of k, then the remaining nodes at the end should 
  be kept as is and not reversed.
Do not change the values of the nodes, only change the links between nodes.

Examples
Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
Output :head -> 2 -> 1 -> 4 -> 3 -> 5
Explanation :The groups 1 -> 2 and 3 -> 4 were reversed as 2 -> 1 and 4 -> 3.

Input :head -> 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output :head -> 3 -> 2 -> 1 -> 4 -> 5
Explanation :The groups 1 -> 2 -> 3 were reversed as 3 -> 2 -> 1.
Note that 4 -> 5 was not reversed.
*/


#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node* next;
    Node* prev;

    // comnnstructor
    Node(int data1,Node* next1,Node* prev1){
        data=data1;;
        next=next1;
        prev=prev1;

    }

    // 2nd constructor to avoid passing null in pointer wen nothing ahead

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

};


Node* revll(Node* head){
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node *getkthNode(Node *temp,int k){
    k-=1;
    while (temp!=NULL && k>0)
    {   
        k--;
        temp=temp->next;
    }
    return temp;
    
}

Node *kReverse(Node* head,int k){
    Node* temp=head;
    Node* prevLast=NULL;
    while(temp!=NULL){
        Node* kthNode=getkthNode(temp,k);
        if(kthNode==NULL){
            if(prevLast) prevLast->next=temp;
            break;
        }

        Node* nextNode=kthNode->next;
        kthNode->next=NULL;
        revll(temp);
        if(temp==head) head=kthNode;
        else prevLast->next=kthNode;

        prevLast=temp;
        temp=nextNode;
    }
    return head;
}