/*
Flattening a Linked List


5

Problem Statement: Given a linked list containing ‘N’ head nodes 
where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head

Each of these child linked lists is in sorted order and connected by a 
'child' pointer. Your task is to flatten this linked list such that all nodes 
appear in a single layer or level in a 'sorted order'.
*/


#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node *child;
    Node() {
        val = 0;
        next = NULL;
        child = NULL;
    }
    Node(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }
    Node(int data1, Node *next1, Node* next2) {
        val = data1;
        next = next1;
        child = next1;
    }
};


Node* merge(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(list1 != NULL && list2!=NULL){
        if(list1->val < list2->val){
            res->child=list1;
            res=list1;
            list1=list1->child;
        }else{
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=nullptr;
    }
    if(list1) res->child=list1;
    else res->child=list2;
    if(dummyNode->child) dummyNode->child->next=nullptr;
    return dummyNode->child;
} 

Node* flatten(Node* head){
    if(head==NULL || head->next==NULL) return head;

    Node*mergeHead=flatten(head->next);
    head=merge(head,mergeHead);
    return head;
}