/*
Implement Lower Bound


23

Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

What is lower bound?
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

Examples
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
            
*/

#include <bits/stdc++.h>
using namespace std;


// mine brute force O(n) linear search
// binary appraoch-> find the target and store teh index in ans 
// and dont stop continue searching in last check
// if low>high and ans!=-1
// return as else return -1

// sir
// same as mine if even found keep doing
int lb(vector<int> arr,int target){
    int n=arr.size();
    int low=0,high=n-1,ans=n;
    while(low<high){
        int mid=(low+high)/2;
        
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

// for c++ direc interview use 
int lb_direct(vector<int> arr,int target){
    int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    // this give iterator so to get the index-arr.begin() to get index
    return lb;
}

// upper bound arr[index]> target not like in 

int ub(vector<int> arr,int target){
    int n=arr.size();
    int low=0,high=n-1,ans=n;
    while(low<high){
        int mid=(low+high)/2;
        
        if(arr[mid]>target){ //only difference
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
