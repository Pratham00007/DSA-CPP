/*
Search Element in a Rotated Sorted Array


22

Problem Statement: Given an integer array nums, 
sorted in ascending order (with distinct values) and a target value k. 
The array is rotated at some pivot point that is unknown. Find the index at which k 
is present and if k is not present return -1.

Examples
Input:nums = [4, 5, 6, 7, 0, 1, 2], k = 0
Output :4
Explanation : Here, the target is 0. We can see that 0 is present in the given rotated 
sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present 
in the array.

Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3
Output :-1
Explanation :Here, the target is 3. Since 3 is not present in the given rotated sorted array. 
Thus, we get the output as -1.
*/


#include <bits/stdc++.h>
using namespace std;

// mine 
// 1. brute linear search
// 2. sort then search
// 3. find the rotated index and then search in 2 aray 

// sir
// you go to some index now from there you can see if starting is less then that it means left half is sorted na

// see here we see from mid if its sorted then check if leelment in left half
// if element is not in left half remoive from search

int search(vector<int>arr , int target){
    int high=arr.size()-1,low=0;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==target){
            return mid;
        }

        // now checking if left half is sorted
        if(arr[low]<=arr[high]){
            // now check if elemnt is in left half
            if(target>=arr[low] && target <=arr[high]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

    }
    else{
        if(target>=arr[mid] && target <= arr[high]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;

}