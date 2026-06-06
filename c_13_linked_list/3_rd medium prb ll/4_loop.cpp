/*
Detect a Cycle in a Linked List


7

Problem Statement: Given a Linked List, determine whether the linked list contains a cycle or not.

Examples
Input: LL: 1 2 3 4 5

Output: True
Explanation: The last node with the value of 5 has its 'next' pointer pointing back to a previous node with the value of 3. This has resulted in a loop, hence we return true.
Input: LL: 1 2 3 4 9 9

Output: False
Explanation:  In this example, the linked list does not have a loop hence returns false. 
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

// mine stack me next pointer ka address push karo if repeat then return true else false

bool loop(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast) return true;
    }
    return false;


}