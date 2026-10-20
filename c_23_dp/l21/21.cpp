#include<bits/stdc++.h>
using namespace std;

int findways(vector<int>&nums,int tar){
    int n=nums.size();
    vector<int>prev(tar+1,0),cur(tar+1,0);
    if(nums[0]==0) prev[0]=2;
    else prev[0]=1;
    if(nums[0]!=0 && nums[0]<=tar) prev[nums[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int nottake=prev[sum];
            int take=0;
            if(nums[ind]<=sum) take=prev[sum-nums[ind]];

            cur[sum]=(nottake+take);
        }
        prev=cur;

    }
    return prev[tar];
}

int cntpartition(int n,int d,vector<int>&arr){
    int tosum=0;
    for(auto &it:arr) tosum+=it;
    if(tosum-d<0 || (tosum-d)%2) return false;
    return findways(arr,(tosum-d)/2);
}

int findTargetSumWays(vector<int>& nums, int target) {

        return cntpartition(nums.size(),target,nums);
    }