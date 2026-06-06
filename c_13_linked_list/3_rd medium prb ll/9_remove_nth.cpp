/*
Remove N-th node from the end of a Linked List


Problem Statement: Given a linked list and an integer N, the task is to delete
 the Nth node from the end of the linked list and print the updated linked list.

Examples
Input:  5->1->2, N=2
Output: 5->2
Explanation: The 2nd node from the end of the linked list is 1. Therefore,
 we get this result after removing 1 from the linked list.

Input:  1->2->3->4->5, N=3
Output: 1->2->4->5
Explanation: The 3rd node from the end is 3, therefore, we remove 3 from the linked list.
*/

// SIR m1 go to n then again n-k (before delting node) then normally delete
// m2 fast and slow pointer to 


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

Node* removekth(Node * head , int k){
    Node* fast=head;
    Node*slow=head;
    for(int i=0;i<k;i++) fast=fast->next;
    if(fast==NULL) return head->next;
    while (fast->next != NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }

    Node* delNode=slow->next;
    slow->next=slow->next->next;
    free(delNode);
    return head;
    
}