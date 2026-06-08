/*
Rotate a Linked List


Problem Statement: Given the head of a singly linked list containing integers,
 shift the elements of the linked list to the right by k places and return the head
  of the modified list. Do not change the values of the nodes, only change the links between nodes.

Examples
Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
Output : head -> 4 -> 5 -> 1 -> 2 -> 3
Explanation :List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.
List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 4
Output :head -> 2 -> 3 -> 4 -> 5 -> 1
Explanation :List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.
List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.
List after 3 shift to right: head -> 3 -> 4 -> 5 -> 1 -> 2.
List after 4 shift to right: head -> 2 -> 3 -> 4 -> 5 -> 1. 
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

Node*findnithNode(Node* temp, int k){
    int cnt=1;
    while(temp!=NULL){
        if(cnt==k) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}

Node* rotatek(Node* head, int k){
    if(head==NULL || k==0) return head;
    Node* tail=head;
    int len=1;
    while(tail->next != NULL){
        tail=tail->next;
        len+=1;

    }

    if (k%len==0) return head;

    k=k%len;

    tail->next=head;
    Node* newLastNode=findnithNode(head,len-k);

    head=newLastNode->next;
    newLastNode->next=NULL;

    return head;
}