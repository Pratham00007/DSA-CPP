/*
Find middle element in a Linked List


9

Problem Statement: Given the head of a linked list of integers, 
determine the middle node of the linked list. However, if the linked list has an 
even number of nodes, return the second middle node.

Examples
Example 1:
Input:
 LL: 1  2  3  4  5 
                       


Output:
 3
                
Explanation: 
Node with value 3 is the middle node of this linked list.
                                         
Example 2:
Input:
 LL: 1  2  3  4  5  6
                          


Output: 
4
                
Explanation: 
 In this example, the linked list has an even number of nodes hence we return the second middle 
 node which is 4.
 
 
*/

#include<bits/stdc++.h>
using namespace std;

// mine simple find no of ele then go to middle and print 
// sir better-> tortoise and hare


// just to avoid error i added node code
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

Node *findmiddle(Node *head){
    Node *slow=head;
    Node* fast= head;

    while (fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}