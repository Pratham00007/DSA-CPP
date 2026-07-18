/*
Count number of nice subarrays

Problem Statement: Given an array nums and an integer k. An array is called nice
 if and only if it contains k odd numbers. Find the number of nice subarrays
  in the given array nums. A subarray is continuous part of the array.

Examples

Input :nums = [1, 1, 2, 1, 1] , k = 3
Output :2
Explanation :The subarrays with three odd numbers are [1, 1, 2, 1] [1, 2, 1, 1]

Input : nums = [4, 8, 2] , k = 1
Output :0
Explanation :The array does not contain any odd number.
*/


#include<bits/stdc++.h>
using namespace std;


int bin_arr(vector<int>arr,int goal){
    if(goal<0) return 0;
    int l=0,r=0,sum=0,cnt=0;
    while(r<arr.size()){
        sum += (arr[r]%2);
        while(sum>goal){
            sum-=(arr[l]%2);
            l++;
        }
        cnt=cnt+(r-l+1);
        r=r+1;
    }
    return cnt;
}



    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=(bin_arr(nums,k)-bin_arr(nums,k-1));
        return ans;
    }

int main(){

}