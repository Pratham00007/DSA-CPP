/*
Check for Balanced Parentheses


4

Problem Statement: Check Balanced Parentheses. Given string str containing just the characters '(', ')', '{', '}', '[' and ']', check if the input string is valid and return true if the string is balanced otherwise return false. .

Note:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Examples
Example 1:
Input: str = “( )[ { } ( ) ]”
Output: True
Explanation: As every open bracket has its corresponding close bracket. 
Match parentheses are in correct order hence they are balanced.


Example 2:
Input: str = “[ ( )”
Output: False
Explanation: As ‘[‘ does not have ‘]’ hence it is not valid and will return false.
            
*/

#include<bits/stdc++.h>
using namespace std;

  bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();
                
                if(s[i]==')' && ch=='('  || s[i]==']' && ch=='['  || s[i]=='}' && ch=='{' ) continue;
                else return false;
            }
        }
        return st.empty();
    }