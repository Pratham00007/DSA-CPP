/*
Delete the Middle Node of the Linked List


4

Problem Statement: Given the head of a linked list of integers, 
delete the middle node of the linked list and return the modified head.
 However, if the linked list has an even number of nodes, delete the second middle node.

Examples
Input: 1->2->3->4->5 

Output: 1->2->4->5

Explanation: Node with value 3 is at the middle node and deleted.
Input: 1->2->3->4

Output: 1->2->4

Explanation: The linked list has an even number of nodes hence we delete the 
second middle node which is 3.
*/

// tortoise and haer logicc and one pointer below the slow 

// sir same mine but instaed of third variable just skip to move slow one time 


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


Node* delmid(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node*slow=head;Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
    return head;

}