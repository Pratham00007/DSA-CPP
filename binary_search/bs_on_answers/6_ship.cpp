/*
Capacity to Ship Packages within D Days


8

Problem Statement: You are the owner of a Shipment company. 
You use conveyor belts to ship packages from one port to another. 
The packages must be shipped within 'd' days.
 The weights of the packages are given in an array 'of weights'. 
 The packages are loaded on the conveyor belts every day in the same 
 order as they appear in the array. The loaded weights must not exceed
  the maximum weight capacity of the ship. Find out the least-weight capacity
   so that you can ship all the packages within 'd' days .

Examples

Input: N = 5, weights = [5, 4, 5, 2, 3, 4, 5, 6], d = 5
Output: 9
Explanation: The minimum ship capacity needed to ship all packages within 5 days is 9.

Input: N = 3, weights = [1, 2, 3, 4, 5], d = 2
Output: 9
Explanation: With a capacity of 9, the packages can be shipped in 2 days as [1,2,3,4] and [5].
*/

// explaination in md file

// sir
#include <bits/stdc++.h>
using namespace std;

int finddays(vector<int>weights, int cap){
    int days=1,load=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+load > cap){
            days+=1;
            load=weights[i];
        }else{
            load+=weights[i];
        }

    }return days;

}

int bs(vector<int>weights,int d){
    // low will be max of arr and high will be sum of array
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int noofdays=finddays(weights,mid);
        if(noofdays<=d){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
     
}