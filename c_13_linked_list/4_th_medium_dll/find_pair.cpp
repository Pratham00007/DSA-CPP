/*
copied from greeeks bcs not available artice

Find pairs with given sum in doubly linked list
Last Updated : 23 Jul, 2025
Given a sorted doubly linked list of positive distinct elements,
 the task is to find pairs in a doubly-linked list whose sum is equal
  to the given value x in sorted order.

Examples:

Input:

Find-pairs-with-given-sum-in-doubly-linked-list
 

Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs (1, 6) and (2, 5) with sum 7.

Input: 

Find-pairs-with-given-sum-in-doubly-linked-list-2
 


Output: (1,5)
Explanation: We can see that there is one pair (1, 5) with a sum of 6.
*/


#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node* next;
    Node* prev;

    // comnnstructor
    Node(int data1,Node* next1,Node* prev1){
        data=data1;;
        next=next1;
        prev=prev1;

    }

    // 2nd constructor to avoid passing null in pointer wen nothing ahead

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

};

// optimal 2 pointer apprach
Node* findtail(Node*head){
  Node*tail=head;
  while(tail->next!=NULL) tail=tail->next;
  return tail;
}

vector<pair<int,int>>findPairs(Node* head,int k){
  vector<pair<int,int>>ans;
  if(head==NULL ) return ans;
  Node* left=head;
  Node*right= findtail(head);

  while (left->data<right->data)
  {
    if(left->data+right->data==k){
      ans.push_back({left->data,right->data});
      left=left->next;
      right=right->next;
    }
    else if(left->data +right->data<k){
      left=left->next;
    }
    else right=right->prev;
  }
  
  return ans;
}


