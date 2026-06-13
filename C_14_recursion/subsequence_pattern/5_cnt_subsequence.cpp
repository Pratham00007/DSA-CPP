/*
Count all subsequences with sum K


8

Problem Statement: Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

Examples
Example 1:
Input :
 nums = [4, 9, 2, 5, 1] , k = 10
Output :
 2
Explanation :
 The possible subsets with sum k are [9, 1] , [4, 5, 1].

Example 2:
Input :
 nums = [4, 2, 10, 5, 1, 3] , k = 5
Output :
 3
Explanation :
 The possible subsets with sum k are [4, 1] , [2, 3] , [5].
*/

// create all subsequence then pass on check if yes add toanswer else not 

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to count subsequences
    // with the target sum
    int func(int ind, int sum, vector<int> &nums) {
        // Base case: if sum is 0, one valid
        // subsequence is found
        if (sum == 0) return 1;
        // Base case: if sum is negative or 
        // index exceeds array size
        if (sum < 0 || ind == nums.size()) return 0;
        // Recurse by including current number
        // or excluding it from the sum
        return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
    }

public:
    // Function to start counting subsequences
    int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    cout << "Number of subsequences with target sum " << target << ": "
         << sol.countSubsequenceWithTargetSum(nums, target) << endl;
    return 0;
}
