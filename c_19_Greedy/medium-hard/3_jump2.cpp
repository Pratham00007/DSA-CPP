/*
Jump Game 2


3

Problem Statement: You are given a 0-indexed array nums of length n representing your maximum jump capability from each index.

You start at index 0. Each element nums[i] represents the maximum number 
of steps you can jump forward from index i.
Your goal is to reach the last index of the array (nums[n - 1]) using the 
minimum number of jumps
Return the minimum number of jumps required to reach the last index.
You can assume that it is always possible to reach the last index.

Examples
Input: nums = [2, 3, 1, 1, 4]

Output: 2
Explanation: Jump from index 0 → 1 → 4.



Input:
 nums = [2, 3, 0, 1, 4]

Output:
 2
Explanation:
 Jump from index 0 → 1 → 4.

*/

#include<bits/stdc++.h>
using namespace std;

 int jump(vector<int>& nums) {
        return minJumps(nums, 0);
    }

    int minJumps(vector<int>& nums, int position) {
        // If we are already at or beyond the last index, no more jumps needed
        if (position >= nums.size() - 1) return 0;

        // If we can't move from current position
        if (nums[position] == 0) return INT_MAX;

        int minStep = INT_MAX;

        // Try every possible jump from 1 to nums[position]
        for (int jump = 1; jump <= nums[position]; ++jump) {
            int subResult = minJumps(nums, position + jump);

            // If the result is not INT_MAX, update minimum step
            if (subResult != INT_MAX)
                minStep = min(minStep, 1 + subResult);
        }

        return minStep;
    }

int main(){

}