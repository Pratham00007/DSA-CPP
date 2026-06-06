/*
Starting point of loop in a Linked List

Problem Statement: Given the head of a linked list that may contain a cycle,
 return the starting point of that cycle. If there is no cycle in the linked list return null.

Examples
Input: LL: 1  2  3  4  5
Output: 3
Explanation: This linked list contains a loop of size 3 starting at node with value 3.


Input: LL: 1 -> 2 -> 3 -> 4 -> 9 -> 9
Output:NULL
Explanation: This linked list does not contain a loop hence has no starting point

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

Node* loop_st(Node* head){
    Node* sl=head;
    Node* fs=head;

    while(fs!=NULL && fs->next !=NULL){
        sl=sl->next;
        fs=fs->next->next;

        if(sl==fs){
            sl=head;
            while(sl!=fs){
                sl=sl->next;
                fs=fs->next;
            }
            return sl;
        }
    }
    return NULL;
    
}