/*
Add two numbers represented as Linked Lists

Problem Statement: Add two numbers represented as Linked Lists.

Examples

Example 1:
Input: num1 = 243, num2 = 564
Output:sum = 807; L = [7,0,8]



Explanation: Since the digits are stored in reverse order, 
reverse the numbers first to get the or original number and then add them as → 342 + 465 = 807. 

Example 2:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: Result: [8,9,9,9,0,0,0,1]



Explanation: Since the digits are stored in reverse order, 
reverse the numbers first to get the original number and then add them
 as → 9999999 + 9999 = 8999001. Refer to the image below.
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

Node* addno(Node *num1, Node* num2){
    Node* dummyHead=new Node(-1);
    Node *curr=dummyHead;
    Node* temp1=num1;
    Node* temp2=num2;
    int carry =0;
    while(temp1 != NULL || temp2!=NULL){
        int sum=carry;
        if(temp1) sum+= temp1->data;
        if(temp2) sum+= temp2->data;
        Node* newNode=new Node(sum%10);
        carry=sum/10;

        curr->next=newNode;
        curr=curr->next;

        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
             

    }
    if(carry){
        Node* newNode=new Node(carry);
        curr->next=newNode;
    }

    return dummyHead->next;
}