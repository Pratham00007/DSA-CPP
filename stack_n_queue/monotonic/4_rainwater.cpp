/*
Trapping Rainwater


9

Problem Statement: Given an array of non-negative integers representation
 elevation of ground. Your task is to find the water that can be trapped after rain .

Examples

Input : height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output : 6
Explanation : Water is trapped in the dips between bars.
 The total trapped water units add up to 6 (1+1+2+1+1).

Input : height = [4,2,0,3,2,5]
Output : 9
Explanation : The elevation map traps 9 units of water in total,
 as water fills the spaces between higher bars on both sides.
*/


#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>&height){
    int n=height.size();

    int left=0;
    int right=n-1;

    int maxleft=0;
    int maxRight=0;

    int totalWater=0;

    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>=maxleft){
                maxleft=height[left];
            }else{
                totalWater += maxleft-height[left];
            }
            left++;
        }else{
            if(height[right]>=maxRight){
                maxRight=height[right];
            }else{
                totalWater+=maxRight-height[right];
            }
            right--;
        }
    }
    return totalWater;
}