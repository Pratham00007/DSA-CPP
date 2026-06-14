/*
Subset - II | Print all the Unique Subsets


5

Problem Statement: Given an integer array nums, which can have duplicate entries, 
provide the power set. Duplicate subsets cannot exist in the solution set.
 Return the answer in any sequence.

Examples
Input: array[] = [1,2,2]
Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]
Explanation: We can have subsets ranging from  length 0 to 3. which are listed above.
 Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

Input: array[] = [1]
Output: [ [ ], [1] ]
Explanation: Only two unique subsets are available.
*/

#include<bits/stdc++.h>
using namespace std;

void findSubset(int ind,vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i!=ind && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        findSubset(i+1,nums,ds,ans);
        ds.pop_back();
    }
}
    vector<vector<int>>subsetWithDub(vector<int>&nums){
        vector<vector<int>>ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubset(0,nums,ds,ans);
        return ans;
}
