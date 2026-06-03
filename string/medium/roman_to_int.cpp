/*
Roman Numerals to Integer


8

Problem Statement: Roman numerals are represented by seven different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
Roman numerals are usually written largest to smallest from left to right. But in six special cases, subtraction is used instead of addition:
I before V or X → 4 and 9,
X before L or C → 40 and 90,
C before D or M → 400 and 900
Given a Roman numeral, convert it to an integer.

Examples
Example 1:
Input:
 s = "LVIII"
Output:
 58
Explanation:
 L = 50, V= 5, III = 3.

Example 2:
Input:
 s = "MCMXCIV"
Output:
 1994
Explanation:
 M = 1000, CM = 900, XC = 90 and IV = 4.
*/


#include <bits/stdc++.h>
using namespace std;

int romantoint(string s){
    unordered_map<char,int>mp;
    
    mp['I'] =             1;
    mp['V'] =             5;
    mp['X'] =             10;
    mp['L'] =             50;
    mp['C'] =             100;
    mp['D'] =             500;
    mp['M'] =             1000;

    int ans=0;

    for(int i=0;i<s.length();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            ans-=mp[s[i]];
        }else{
            ans+=mp[s[i]];
        }
    }
    return ans;
}