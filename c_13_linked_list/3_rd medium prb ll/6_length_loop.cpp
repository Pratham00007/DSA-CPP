/*
Length of Loop in Linked List


13

Problem Statement: Given the head of a linked list, determine the length of a loop
 present in the linked list. If there's no loop present, return 0.

Examples
Input: 

Output: 3
Explanation: A cycle exists in the linked list starting at node
 3 -> 4 -> 5 and then back to 3. There are 3 nodes present in this cycle.
Input: 

Output: 0
Explanation: The linked list is linear and does not have a loop hence return 0.
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

int len_loop(Node * slow,Node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
    }
    return cnt;
}

int loop_st(Node* head){
    Node* sl=head;
    Node* fs=head;

    while(fs!=NULL && fs->next !=NULL){
        sl=sl->next;
        fs=fs->next->next;

        if(sl==fs){
            return len_loop(sl,fs);
            }
            
        }
    
    return 0;
    
}