/*
Longest Palindromic Substring

Problem Statement: Given a string s, return the longest palindromic substring in s.

Examples
Example 1:
Input:
 s = "babad"
Output:
 "bab"
Explanation:
 It is the longest palindromic substring. "aba" is also a valid answer.

Example 2:
Input:
 s = "cbbd"
Output:
 "bb"
Explanation:
 It is the longest palindromic substring.
*/


#include <bits/stdc++.h>
using namespace std;
bool ispalin(string &s){
    int j=s.size()-1;
    int i=0;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++, j--;
    }
    return true;
}

string logpain(string &s){
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++){
        string tmp="";
        for(int j=i;j<n;j++){
            tmp+=s[j];
            if(ispalin(tmp) && tmp.size()>ans.size()){
                ans=tmp;
            }
        }
    }
    return ans;
}