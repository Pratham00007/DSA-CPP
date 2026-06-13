/*
Generate Paranthesis


5

Problem Statement: Given n pairs of parentheses, write a function to generate 
all combinations of well-formed parentheses.

Examples
Example 1:
Input:
 n = 3
Output:
 ["((()))", "(()())", "(())()", "()(())", "()()()"]

Example 2:
Input:
 n = 1
Output:
 ["()"]
*/



#include <bits/stdc++.h>
using namespace std;


// recursive

void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    if (open < n) backtrack(curr + '(', open + 1, close, n, res);
    if (close < open) backtrack(curr + ')', open, close + 1, n, res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;
}


// brute


void backtrack(string curr, int open, int close, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    if (open < n) backtrack(curr + '(', open + 1, close, n, res);
    if (close < open) backtrack(curr + ')', open, close + 1, n, res);
}

vector<string> generateParenthesis2(int n) {
    vector<string> res;
    backtrack("", 0, 0, n, res);
    return res;
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for (string s : result) cout << s << endl;
    return 0;
}