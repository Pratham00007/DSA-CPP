/*
Remove Outermost Parentheses


Problem Statement: A valid parentheses string is defined by the following rules:

It is the empty string "".
If A is a valid parentheses string, then so is "(" + A + ")".
If A and B are valid parentheses strings, then A + B is also valid.

A primitive valid parentheses string is a non-empty valid string that cannot
 be split into two or more non-empty valid parentheses strings.

Given a valid parentheses string s, your task is to remove the outermost parentheses
 from every primitive component of s and return the resulting string.

Examples
Example 1:
Input:
 s = "((()))"
Output:
 "(())"
Explanation:
 The input string is a single primitive: "((()))".  
Removing the outermost layer yields: "(())".

Example 2:
Input:
 s = "()(()())(())"
Output:
 "(()())()"
Explanation:
 Primitive decomposition: "()" + "(()())" + "(())"  
After removing outermost parentheses: "" + "()()" + "()"
Final result: "(()())()".
*/

#include <bits/stdc++.h>
using namespace std;

// m-1 stack based so sc O(n) 

// m-2 counter approach same like stack but no sc

string removeparent(string s){
    int cnt=0;
    string ans="";
    for(int i=0;i<s.length();i++){
        if (s[i]==')') cnt --;
        if(cnt != 0)ans.push_back(s[i]);
        if(s[i]=='(') cnt++;
    }
    return ans;
}