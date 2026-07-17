/*
Max Consecutive Ones III


Problem Statement: Given a binary array nums and an integer k, return the maximum number
 of consecutive 1's in the array if you can flip at most k 0's.

Examples
Input : nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0] , k = 3
Output : 10
Explanation : The maximum number of consecutive 1's are obtained only if we flip 
the 0's present at position 3, 4, 5 (0 base indexing).
The array after flipping becomes [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0].
The number of consecutive 1's is 10.


Input : nums = [0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1] , k = 3
Output : 9
Explanation : The underlines 1's are obtained by flipping 0's in the new array.
[1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1].
The number of consecutive 1's is 9.
*/

#include<bits/stdc++.h>
using namespace std;

 int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,zeros=0,maxlen=0;
        while(r<nums.size()){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k) {
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }

int main(){

}