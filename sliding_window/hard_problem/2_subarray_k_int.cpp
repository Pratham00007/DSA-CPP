/*
Subarray with k different integers


4

Problem Statement: You are given an integer array nums and an integer k. 
Return the number of good subarrays of nums.

A good subarray is defined as a contiguous subarray of nums that contains exactly k
 distinct integers. A subarray is a contiguous part of the array.

Examples
Input: nums = [1, 2, 1, 2, 3], k = 2  
Output: 7
Explanation: The 7 subarrays with exactly 2 different integers are:
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]


Input: nums = [1, 2, 1, 3, 4], k = 3  
Output: 3
Explanation: The 3 subarrays with exactly 3 different integers are:  
[1,2,1,3], [2,1,3], [1,3,4] 
*/

#include<bits/stdc++.h>
using namespace std;

int sub_l_e_k(vector<int>nums,int k){
    int l=0,r=0,cnt=0;
    map<int,int>mpp;

    while(r<nums.size()){
        mpp[nums[r]]++;
        while(mpp.size()<=k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l=l-1;
        }
        cnt=cnt+(r-l+1);
        r=r+1;
    }
    return cnt;
}

int sub_e_k(vector<int>nums,int k){
    return (sub_l_e_k(nums,k)-sub_l_e_k(nums,k-1));
}

int main(){

}