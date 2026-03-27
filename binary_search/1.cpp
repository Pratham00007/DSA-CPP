#include <bits/stdc++.h>
using namespace std;



    int bs_iterative(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]==target) return mid;
            else if(target>nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    } 
    
    int bs_recursive(vector<int>&nums,int low,int high,int target){
        if (low>high){
            return -1;
        }
        int mid=(low+high)/2;
        if(target==nums[mid]){
            return mid;
        }else if(target>nums[mid]){
            return bs_recursive(nums,mid+1,high,target);

        }else{
            return bs_recursive(nums,low,mid-1,target);
        }
    }