/*
Length of Longest Substring without any Repeating Character


15

Problem Statement: Given a string, S. Find the length of the longest substring 
without repeating characters.

Examples
Example 1:
Input:
 S = "abcddabac"  
Output:
 4  
Explanation:
 The longest substring with distinct characters is "abcd", which has a length of 4.

Example 2:
Input:
 S = "aaabbbccc"  
Output:
 2  
Explanation:
 The longest substrings with distinct characters are "ab" and "bc", both having a length of 2.
*/

#include<bits/stdc++.h>
using namespace std;

int max_sub(string s){
    int n=s.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        vector<int>hash(256,0);
            for(int j=i;j<n;j++){
                if (hash[s[j]]==1) break;

                hash[s[j]]=1;

                int len=j-i+1;
                
            maxlen=max(len,maxlen);
            }

    }
    return maxlen;
}

int max_sub_opt(string s){
    int l=0,r=0,maxlen=0;
    int n=s.size();
    vector<int>hash(256,-1);
    while (r<n)
    {
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
        }
        int len=r-l+1;
        maxlen=max(len,maxlen);
        hash[s[r]]=r;
        r++;
    }
    return maxlen;
    
}

int main(){
 string input = "abcddabac";
    
    //Create an instance of Solution class
  
    
    int length = max_sub(input);
    
    //Print the result
    cout << "Length of longest substring without repeating characters: " << length << endl;
    
    return 0;
}