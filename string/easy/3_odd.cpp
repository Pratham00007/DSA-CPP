/*
Largest Odd Number in a String.


10
Problem Statement: Given a string s, representing a large integer,
 the task is to return the largest-valued odd integer (as a string) 
 that is a substring of the given string s.
The number returned should not have leading zero's. But the given input string 
may have leading zero.

Examples

Example 1
Input:
 s = "5347"
Output:
 "5347"
Explanation:
 The odd numbers formed by the given string are → 5, 3, 53, 347, 5347. 
 The largest odd number without leading zeroes is 5347.

Example 2
Input:
 s = "0214638"
Output:
 "21463"
Explanation:
 The odd numbers formed by the string are → 1, 3, 21, 63, 463, 1463, 21463. 
 We can't use numbers starting with 0, so the largest valid odd number is 21463.

*/

// maam 
// go right to left if any odd no then return from 0 to that index 
// IMP-> to get the no form string just -'0' meas ascii value so you get original number


#include<bits/stdc++.h>
using namespace std;

string larodd(string num){
    int n=num.size();
    for(int i=n;i>=0;i--){
        if((num[i]-'0')%2 != 0) {
            return num.substr(0,i+1);
        }
    }
    return "";
}