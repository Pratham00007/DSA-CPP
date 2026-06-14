/*
Check if there exists a subsequence with sum K


2

Problem Statement: Given an array nums and an integer k. Return true if there exist
 subsequences such that the sum of all elements in subsequences is equal to k else false.

Examples
Example 1:
Input :
 nums = [1, 2, 3, 4, 5] , k = 8
Output :
 Yes
Explanation :
 The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

Example 2:
Input :
 nums = [4, 3, 9, 2] , k = 10
Output :
 No
Explanation :
 No subsequence can sum up to 10.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // This method recursively checks for the subsequence with the given sum
    bool func(int ind, int sum, std::vector<int> &nums) {
        // Base case: if all elements are processed, check if sum is 0
        if (ind == nums.size()) {
            return sum == 0;
        }
        // Recursive call: include the current element in the subsequence
        // or exclude the current element from the subsequence
        return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
    }

public:
    // This method initiates the recursive process
    bool checkSubsequenceSum(std::vector<int>& nums, int target) {
        return func(0, target, nums); // Start the recursive process
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 4};
    int target = 5;
    cout << sol.checkSubsequenceSum(nums, target); // Expected output: true
    return 0;
}
