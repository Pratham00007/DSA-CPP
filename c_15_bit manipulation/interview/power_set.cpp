/*
Power Set | Bit Manipulation


3

Problem Statement: Given an array of numbers, print all subsets of it using bitwise operators.

Examples
Input: nums = [1, 2, 3]
Output: [[ ], [1], [2], [3], [1, 2], [2, 3], [3, 1], [1, 2, 3]]
Explanation:  A power set of an array is an array of all possible subarrays,
including an empty array. It contains all combinations of elements from the original array.
By iterating through all possible combinations of the elements in the input array
we are able to get the power set of the array.

Input: nums = [5, 7, 8]
Output: [[ ], [5], [7], [8], [5, 7], [7, 8], [8, 5], [5, 7, 8]]
Explanation:  A power set of an array is an array of all possible subarrays,
 including an empty array. It contains all combinations of elements from the original array.
  By iterating through all possible combinations of the elements in the input array
  we are able to get the power set of the array.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{

    int n = nums.size();
    // calculating total no of subset
    int subsets = 1 << n;
    vector<vector<int>> ans;

    for (int num = 0; num < subsets; num++)
    {
        // temp to hold current subset
        vector<int> subset;

        for (int i = 0; i < n; i++)
        {
            // if ith bit is set then include
            if (num & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}