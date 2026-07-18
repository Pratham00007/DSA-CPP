/*
Binary subarray with sum


Problem Statement: You are given a binary array nums (containing only 0s 
and 1s) and an integer goal. Return the number of non-empty subarrays of 
nums that sum to goal. A subarray is a contiguous part of the array.

Examples
Input: nums = [1, 0, 0, 1, 1, 0], goal = 2  
Output: 6
Explanation: There are 6 subarrays with sum exactly equal to 2:
[1, 0, 0, 1], [0, 0, 1, 1], [0, 1, 1], [1, 1], [1, 1, 0], [0,0,1,1,0]


Input: nums = [0,0,0,0,0,0], goal = 0  
Output: 21  
Explanation: All subarrays with only 0s will have sum = 0.  
There are 21 such subarrays in total (n(n+1)/2 = 6*7/2 = 21).
*/

#include<bits/stdc++.h>
using namespace std;

int bin_arr(vector<int>arr,int goal){
    if(goal<0) return 0;
    int l=0,r=0,sum=0,cnt=0;
    while(r<arr.size()){
        sum += arr[r];
        while(sum>goal){
            sum-=arr[l];
            l++;
        }
        cnt=cnt+(r-l+1);
        r=r+1;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=(bin_arr(nums,goal)-bin_arr(nums,goal-1));
        return ans;
    }

int main(){
    
}