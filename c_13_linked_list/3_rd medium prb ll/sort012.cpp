/*
Sort a Linked List of 0's 1's and 2's by changing links


4

Problem Statement: Given a linked list containing only 0's, 1's, and 2's, 
sort the linked list by rearranging the links (not by changing the data values).

Examples
Input: 1 -> 2 -> 0 -> 1 -> 0 -> 2 -> NULL
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
Input: 2 -> 1 -> 2 -> 0 -> 0 -> 1 -> NULL
Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
*/


// mine store 0,1,2 then again travese and insert
// m2 link 0s together and 1  and 2 as 3 ll and in last link 0 1 2
// m3 normal sort 

// sir brute mine same cnt 0,1,2
// sir better my logic link 0 ll togetherr , 1togther and 2 together


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

Node* sortList(Node *head){
    if(head || head->next) return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;

    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }

    zero->next=(oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next=twoHead->next;
    two->next=NULL;

    Node* newHead=zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;

}