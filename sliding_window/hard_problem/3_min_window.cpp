/*
Minimum Window substring


0

Problem Statement: Given two strings s and t. Find the smallest window substring of s 
that includes all characters in t (including duplicates) , in the window. 
Return the empty string "" if no such substring exists.

Examples
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring of string s that contains all characters of 
string t is "BANC".

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string is the minimum window that contains all characters 
of the target.
*/

#include<bits/stdc++.h>
using namespace std;

string min_win(string s , string t){
    int n=s.size(), m=t.size() , r=0, l=0, cnt=0, sIndex=-1;
    int minlen=INT_MAX;

    int hash[256]={0};
    for(int i=0;i<m;i++) hash[t[i]]++;

    while(r<n){
        if(hash[s[r]]>0) cnt=cnt+1;
        hash[s[r]]--;

        while(cnt==m){
            if(r-l+1<minlen){
                minlen=r-l+1;
                sIndex=l;
            }

            hash[s[l]]++;
            if(hash[s[l]]>0) cnt=cnt-1;
            l++;
        }
        r=r+1;
    }
    return sIndex==-1 ? "" : s.substr(sIndex,minlen);
}


int main(){

}