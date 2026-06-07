/*
Find intersection of Two Linked Lists


6

Problem Statement: Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. If the two linked lists have no 
intersection at all, return null.

Examples
Example 1:
Input:

List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:

2
Explanation:
 Here, both lists intersecting nodes start from node 2.

Example 2:
Input:

 List1 = [1,2,7], List 2 = [2,8,1]
Output:

 Null
Explanation:
 Here, both lists do not intersect and thus no intersection node is present.

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

Node* inter(Node* firstHead, Node* secondHead){
    if(firstHead == NULL || secondHead==NULL) return NULL;
    Node* temp1=firstHead;
    Node* temp2=secondHead;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;

        if(temp1==temp2) return temp1;

        if(temp1==NULL ) temp1=secondHead;
        if(temp2==NULL ) temp2=firstHead;
    }
    return temp1;
}