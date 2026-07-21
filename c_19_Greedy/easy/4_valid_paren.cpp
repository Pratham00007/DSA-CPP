/*
Valid Paranthesis Checker


Problem Statement: Find the validity of an input string s that only contains
 the letters '(', ')' and '*'. A string entered is legitimate if

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
could be treated as a single right parenthesis ')' or a single left parenthesis 
'(' or an empty string "".
Examples
Input :s = (*))
Output : True
Explanation :The * can be replaced by an opening '(' bracket. The string after
 replacing the * mark is "(())" and is a valid string.

Input : s = *(()
Output :false
Explanation :The * replaced with any bracket does not form a valid string.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
       // Track minimum and maximum open brackets
        int minOpen = 0, maxOpen = 0;

        // Traverse each character in the string
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
                // Treat '*' as '(', ')' or ''
                minOpen--;
                maxOpen++;
            }

            // If maxOpen goes negative, too many closing brackets
            if (maxOpen < 0) return false;

            // minOpen can't be negative
            minOpen = max(minOpen, 0);
        }

        // String is valid if all opens are closed
        return minOpen == 0;
    }

int main(){

}