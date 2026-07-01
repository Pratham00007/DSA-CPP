/*
Find XOR of numbers from L to R


5

Problem Statement: Given two integers L and R. 
Find the XOR of the elements in the range [L , R].

Examples
Example 1:
Input :
 L = 3 , R = 5
Output :
 2
Explanation : 
answer = (3 ^ 4 ^ 5) = 2.

Example 2:
Input :
 L = 1, R = 3
Output :
 0
Explanation : 
answer = (1 ^ 2 ^ 3) = 0.
*/

#include <bits/stdc++.h>
using namespace std;

int xor_till_n(int n){
    if(n%4==1)return 1;
    else if(n%4==2)return n+1;
    else if(n%4==3)return 0;
    else return n;
}

int find_l_r(int l,int r){
    return xor_till_n(l-1)^ xor_till_n(r);
}
