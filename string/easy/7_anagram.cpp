/*
Check if two Strings are anagrams of each other


6

Problem Statement: Given two strings, check if two strings are anagrams of each other or not.



Examples
Example 1:
Input: CAT, ACT
Output: true
Explanation: Since the count of every letter of both strings are equal.

Example 2:
Input: RULES, LESRT 
Output: false
Explanation: Since the count of U and T  is not equal in both strings.

*/


#include<bits/stdc++.h>
using namespace std;

bool isana(string s, string t){
    int n1=s.size(), n2=t.size();
    if (n1!=n2) return false;

    unordered_map<char,int> Map;
    for(int i=0;i<n1;i++){
        Map[s[i]]++;
    }

    for(int i=0;i<n2;i++){
        // if we found it then -1 else return false 
        if(Map.find(t[i])!=Map.end()){
            Map[t[i]]-=1;
        }else{
            return false;
        }
    }

    for(auto items:Map){
        if(items.second!=0) return false;
    }
    return true;
}