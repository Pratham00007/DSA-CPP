/*
Segregate even and odd nodes in LinkedList


8

Problem Statement: Given the head of a singly linked list.
 Group all the nodes with odd indices followed by all the nodes with even indices
  and return the reordered list. Consider the 1st node to have index 1 and so on. 
  The relative order of the elements inside the odd and even group must remain 
  the same as the given input.

Examples
Input: 1→2→3→4→5→6→Null
Output: 2→4→6→1→3→5→Null
Explanation : Odd Nodes in LinkedList are 1,3,5 and Even Nodes in LinkedList are 2,4,6
In Modified LinkedList all even Nodes comes before all Odd Nodes. So Modified 
LinkedList looks like 2→4→6→1→3→5→Null. Order of even and odd Nodes is 
maintained in modified LinkedList.

Input: 1→3→5→Null
Output: 1→3→5→Null
Explanation: As there are no Even Nodes in LinkedList, The Modified LinkedList 
is same as Original LinkedList.
*/

// MINE WITH SC 
// first inssert in stack then in ll
// m-2 traverse with two pointer first pointer stopped at even and other at odd 


#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public: 
    int data;
    ListNode* next;

    // comnnstructor
    ListNode(int data1,ListNode* next1){
        data=data1;;
        next=next1;

    }

    // 2nd constructor to avoid passing null in pointer wen nothing ahead

    public:
    ListNode(int data1){
        data=data1;
        next=nullptr;
    }

};


ListNode* SegregatetoOddEVen(ListNode* head) {
    // Creating dummy heads and tails for even and odd lists
    ListNode* oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode* evenHead = new ListNode(-1), *evenTail = evenHead;

    // Current pointer for traversal
    ListNode* curr = head, *temp;

    while (curr) {
        // Detach current node from the list
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        // Append to odd list if value is odd
        if (temp->data & 1) {
            oddTail->next = temp;
            oddTail = temp;
        }
        // Append to even list if value is even
        else {
            evenTail->next = temp;
            evenTail = temp;
        }
    }

    // Connect even list with odd list
    evenTail->next = oddHead->next;

    // Return head of the new rearranged list
    return evenHead->next;
}