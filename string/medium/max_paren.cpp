/*

Maximum Nesting Depth of Parenthesis


Problem Statement: Given a valid parentheses string s, return the nesting depth of s.
The nesting depth is the maximum number of nested parentheses.

Examples
Example 1:
Input:
 s = "(1+(2*3)+((8)/4))+1"
Output:
 3
Explanation:
 Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input:
 s = "(1)+((2))+(((3)))"
Output:
 3
Explanation:
 Digit 3 is inside of 3 nested parentheses in the string
*/

// same mine logic


#include <bits/stdc++.h>
using namespace std;

int max_paren(string s){
    int res=0,cur=0;
    for(char&c:s){
        if(c=='('){
            cur++;
            res=max(res,cur);

        }
        if(c==')') cur--;
    }
    return res;
}