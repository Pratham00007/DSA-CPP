/*
Delete all occurrences of a key in DLL


0

Problem Statement: Given the head of a doubly linked list and an integer target.
 Delete all nodes in the linked list with the value target and return the head 
 of the modified linked list.

Examples
Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1

Output: head -> 2 <-> 3 <-> 4
Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2

Output: head -> 3 <-> -1 <-> 4
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

// go to the node then just links chnge logic its dll so move back too

Node* delNode(Node* head, int k){
    Node * temp=head;
    while (temp!=NULL)
    {
        if(temp->data==k){
                if(temp==head){
                    head=temp->next;
                }

                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                if(nextNode!=NULL)nextNode->prev=prevNode;

                free(temp);
                temp=nextNode;
            
        }else{
            temp=temp->next;
        }
    }
    return head;
    
}