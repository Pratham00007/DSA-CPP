/*
Isomorphic String


11


Problem Statement: Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Examples
Example 1
Input:
 s = "paper", t = "title"
Output:
 true
Explanation:
 The characters in "s" can be mapped one-to-one to characters in "t": 
'p' → 't', 'a' → 'i', 'e' → 'l', 'r' → 'e'
Since the mapping is consistent and unique for each character, the strings are isomorphic.

Example 2
Input:
 s = "foo", t = "bar"
Output:
 false
Explanation:
 'f' → 'b' is fine, 'o' → 'a' for the first 'o', But the second 'o' in "s" would need to map to 'r' in "t", which conflicts with the earlier mapping of 'o' → 'a'
This inconsistency makes it impossible to convert "s" to "t" using a one-to-one character mapping.
            
*/


#include<bits/stdc++.h>
using namespace std;


bool isom(string s, string t){

    // Arrays to store last seen positions of characters in s and t
          int m1[256] = {0}, m2[256] = {0}; 
          
          // Get the length of the strings
          int n = s.size(); 
          
          // Traverse each character of the strings
          for (int i = 0; i < n; ++i) {
              // If previous positions of current characters differ, return false
              if (m1[s[i]] != m2[t[i]]) return false;
              
              // Update the position with current index + 1
              m1[s[i]] = i + 1;
              m2[t[i]] = i + 1;
          }
          
          // If no mismatch is found, return true
          return true;
}