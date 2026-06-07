/*
Remove duplicates from sorted DLL


4

Problem Statement: Given the head of a doubly linked list with its values 
sorted in non-decreasing order. Remove all duplicate occurrences of any
 value in the list so that only distinct values are present in the list.

Return the head of the modified linked list.

Examples
Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

Output: head -> 1 <-> 3 <-> 4 <-> 5
Explanation: Duplicate occurences of 1 and 3 are deleted
Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

Output: head -> 1 <-> 2
Explanation: All duplicate occurences of 1 is deleted
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

Node* rmovedub(Node *head){
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextNode=temp->next;
        while (nextNode!=NULL && nextNode->data==temp->data)
        {
            Node* dublicate=nextNode;
            nextNode=nextNode->next;
            free(dublicate);
        }
        temp->next=nextNode;
        if(nextNode !=NULL ) nextNode->prev=temp;
        temp=temp->next;
        
    }
    return head;
}