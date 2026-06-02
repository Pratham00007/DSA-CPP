/*
Longest Common Prefix


9

Problem Statement: Write a function to find the longest common prefix string 
amongst an array of strings. If there is no common prefix, return an empty string "".

Examples
Example 1
Input:
 str = ["flower", "flow", "flight"]
Output:
 "fl"
Explanation:
 All strings in the array begin with the common prefix "fl".

Example 2
Input:
 str = ["apple", "banana", "grape", "mango"]
Output:
 ""
Explanation:
 None of the strings share a common starting sequence, so the result is an empty string.
*/


#include<bits/stdc++.h>
using namespace std;

string pref(vector<string>&strs){
    sort(strs.begin(),strs.end());
    int n=strs[0].length();
    string fir=strs[0];
    int j=strs.size();
    string last=strs[j-1];
    string ans;
    for(int i=0;i<n;i++){
        if(fir[i] != last[i]) break;
        ans+= fir[i];
    }
    return ans;
}

int main(){
    vector<string> input = {"interview", "internet", "internal", "interval"};

    // Get the result
    string result = pref(input);

    // Print the result
    cout << "Longest Common Prefix: " << result << endl; 

    return 0;
}