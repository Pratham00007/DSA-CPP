/*
Add 1 to a number represented by LL


3

Problem Statement: Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.

The number will contain no leading zeroes except when the value represented is zero itself.

Examples
Input: 4->5->6

Output: 4->5->7
Explanation: 456 + 1 = 457
Input: 9->9->9

Output: 1->0->0->0
Explanation: 999 + 1 = 1000
*/

// mine go through ll storte no then add then push back brute

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

int addHelper(Node* temp){
    if(temp==NULL) return 1;
    int carry=addHelper(temp->next);
    temp->data += carry;
    if(temp->data <10) return 0;
    temp->data=0;
    return 1;

}

Node *addOne(Node *head){
    int carry=addHelper(head);
    if(carry==1){
        Node* newNode=new Node(1);
        head=newNode;
    }
    return head;
}