/*
Sort a Stack


10

Problem Statement: You are given a stack of integers. Your task is to sort the stack 
in descending order using recursion, such that the top of the stack contains the greatest 
element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort).
 You may only use recursive operations and the standard stack operations (push, pop, peek/top, 
 and isEmpty).

Examples
Example 1:
Input:
 stack = [4, 1, 3, 2]
Output:
 [4, 3, 2, 1]
Explanation:
 After sorting, the largest element (4) is at the top, and the smallest (1) is at 
 the bottom.

Example 2:
Input:
 stack = [1]
Output:
 [1]
Explanation:
 A single-element stack is already sorted.
*/



#include <bits/stdc++.h>
using namespace std;

// Function to insert element in sorted order
void insert(stack<int>& s, int temp) {
    // Base case: if the stack is empty or temp is larger than the top element
    if (s.empty() || s.top() <= temp) {
        s.push(temp);
        return;
    }
    
    // Otherwise, pop the top element and recursively insert
    int val = s.top();
    s.pop();
    insert(s, temp);
    
    // Push the popped element back
    s.push(val);
}

// Function to sort the stack
void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        
        sortStack(s);
        
        insert(s, temp);
    }
}

// Main function
int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    sortStack(s);

    // Print the sorted stack
    cout << "Sorted stack (descending order): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
