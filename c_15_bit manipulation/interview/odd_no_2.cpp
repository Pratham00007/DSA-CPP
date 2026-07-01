/*
Find the two numbers appearing odd number of times

Problem Statement: Given an array nums of length n, every integer 
in the array appears twice except for two integers. Identify and 
return the two integers that appear only once in the array. 
Return the two numbers in ascending order.

For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

Examples
Example 1:
Input:
 nums = [1, 2, 1, 3, 5, 2]
Output:
 [3, 5]
Explanation:

The integers 3 and 5 have appeared only once.

Example 2:
Input:
 nums = [-1, 0]
Output:
 [-1, 0]
Explanation:

The integers -1 and 0 have appeared only once.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums){
    // Variable to store size of array
    int n = nums.size();
    
    // Variable to store XOR of all elements
    long XOR = 0;
    
    // Traverse the array
    for(int i=0; i < n; i++) {
        
        // Update the XOR
        XOR = XOR ^ nums[i];
    }
    
    /* Variable to get the rightmost 
    set bit in overall XOR */
    int rightmost = (XOR & (XOR - 1)) ^ XOR;
    
    /* Variables to stores XOR of
    elements in bucket 1 and 2 */
    int XOR1 = 0, XOR2 = 0;
    
    // Traverse the array
    for(int i=0; i < n; i++) {
        
        /* Divide the numbers among bucket 1
            and 2 based on rightmost set bit */
        if(nums[i] & rightmost) {
            XOR1 = XOR1 ^ nums[i];
        }
        else {
            XOR2 = XOR2 ^ nums[i];
        }
    }
    
    // Return the result in sorted order
    if(XOR1 < XOR2) return {XOR1, XOR2};
    return {XOR2, XOR1};
}