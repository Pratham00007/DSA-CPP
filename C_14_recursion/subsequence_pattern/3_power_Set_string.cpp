/*
Power Set: Print all the possible subsequences of the String


6

Problem Description: Given a string, find all the possible subsequences of the string.

Examples
Input: str = "abc"
Output: [a, ab, abc, ac, b, bc, c]
Explanation: Given string has 7 subsequences.
Input: str = "aa"
Output: [a, a, aa] 
Explanation: Given string has 3 subsequences.
*/


// sir rec

#include <bits/stdc++.h>
using namespace std;

// Solution class to generate all subsequences using recursion
class Solution {
public:
    // Helper recursive function to generate subsequences
    void helper(string &s, int index, string current, vector<string> &result) {
        // Base case: If index reaches string length, add current subsequence to result
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        // Exclude current character and recurse
        helper(s, index + 1, current, result);

        // Include current character and recurse
        current.push_back(s[index]);
        helper(s, index + 1, current, result);

        // Backtrack: remove last character before returning to previous call
        current.pop_back();
    }

    // Function to return all subsequences of string s
    vector<string> getSubsequences(string s) {
        // Vector to store all subsequences
        vector<string> result;  
        // Current subsequence being built
        string current = "";    
        helper(s, 0, current, result);
        return result;
    }
};

int main() {
    // Input string
    string s = "abc";

    // Create Solution object
    Solution sol;

    // Get all subsequences
    vector<string> subsequences = sol.getSubsequences(s);

    // Print all subsequences
    for (auto &subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}
