/*
Longest Substring with At Most K Distinct Characters


9

Problem Statement: Given a string s and an integer k.Find the length 
of the longest substring with at most k distinct characters

Examples

Input :s = "aababbcaacc" , k = 2
Output :6
Explanation :The longest substring with at most two distinct characters is "aababb".
The length of the string 6


Input : s = "abcddefg" , k = 3
Output : 4
Explanation : The longest substring with at most three distinct characters is "bcdd".
The length of the string 4.
*/

#include<bits/stdc++.h>
using namespace std;

int long_sub(string s,int k){
    int maxlen=0,l=0,r=0;
    map<char,int>mpp;
    while(r<s.size()){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0) mpp.erase(mpp[s[l]]);
            l=l+1;
        }

        if(mpp.size()<=k) maxlen=max(maxlen,r-l+1);
        r=r+1;
    }
    return maxlen;
}

int main(){

}