/*
Reverse a Linked List


Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

Examples
Input-  LL: 1   3   2   4 
Output: 3
Explanation: After reversing the linked list, the new head will point to the tail of the old linked list.



*/

// mine current se next ka pointer storein temp
// current ko prev pointer pe map and now go current pointer to temp till temp !=null

// sir brute ->> stack
// better as mine


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