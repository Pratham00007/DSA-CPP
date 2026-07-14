/*
Remove K Digits


8

Problem Statement: Given a string nums representing a non-negative integer, 
and an integer k, find the smallest possible integer after removing k digits from num.

Examples
Example 1:
Input:
 nums = "541892", k = 2
Output:
 "1892"
Explanation:
 Removing the two digits 5 and 4 yields the smallest number, 1892.

Example 2:
Input:
 nums = "1002991", k = 3
Output:
 "21"
Explanation:
 Remove the three digits 1(leading one), 9, and 9 to form the new number 21
 (Note that the output must not contain leading zeroes) which is the smallest.
*/
#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    stack<char>st;
    int n=num.length();
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
            st.pop();
            k=k-1;
        }
        st.push(num[i]);
    }
    while(k>0) {
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    string res="";
    while(!st.empty()){
        res=res+st.top();
        st.pop();
    }


    while(res.size()!=0 && res.back()=='0') res.pop_back();
    reverse(res.begin(),res.end());
    if(res.empty()) return "0";
    return res;

}