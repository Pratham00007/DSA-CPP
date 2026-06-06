/*
Check if the given Linked List is Palindrome


5

Problem Statement: Given the head of a singly linked list representing a
 positive integer number. Each node of the linked list represents a digit of the number,
  with the 1st node containing the leftmost digit of the number and so on. 
  Check whether the linked list values form a palindrome or not. 
  Return true if it forms a palindrome, otherwise, return false. .

A palindrome is a sequence that reads the same forward and backwards.

Examples
Example 1:
Input: head -> 3 -> 7 -> 5 -> 7 -> 3
Output: true
Explanation: 37573 is a palindrome.

Example 2:
Input: head -> 1 -> 1 -> 2 -> 1
Output: false
Explanation: 1121 is not a palindrome.
*/

// mine
// m-1 crete reverse ll too and now check if both are same
// m-2 store in map now again traverse and see if palindrome
// m-3 save the no in travesal and now check if pallindrome


// SIR
// reverse half ll check and again revese back

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


bool ispalin(Node *head){
    if(head==NULL || head->next== NULL) return true;
    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL  && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* newhead=revll(slow->next);
    Node* first=head;
    Node* second=newhead;
    while(second!=NULL){
        if(first->data != second->data){
            revll(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    revll(newhead);
    return true;
}