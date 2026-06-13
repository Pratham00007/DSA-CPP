/*
Generate all binary strings


Problem Statement: Given an integer n, return all binary strings of length n 
that do not contain consecutive 1s. Return the result in lexicographically increasing order.

A binary string is a string consisting only of characters '0' and '1'.

Examples
Example 1:
Input:
 n = 3  
Output:
 ["000", "001", "010", "100", "101"]  
Explanation:
 All binary strings of length 3 that do not contain consecutive 1s.

Example 2:
Input:
 n = 2  
Output:
 ["00", "01", "10"]  
Explanation:
 All binary strings of length 2 that do not contain consecutive 1s.
*/

#include <bits/stdc++.h>
using namespace std;

void generate(int n, string curr, vector<string>& result) {
    // Base case: if length is n, add to result
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // Always try adding '0'
    generate(n, curr + "0", result);

    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result);
    }
}

int main() {
    // Input length n
    int n = 3;

    // Vector to store results
    vector<string> result;

    // Start recursion with empty string
    generate(n, "", result);

    // Print results
    for (string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}