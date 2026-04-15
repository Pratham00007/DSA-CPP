/*
Minimum in Rotated Sorted Array


8

Problem Statement:
Given an integer array arr of size N, sorted in ascending order (with distinct values), the array is rotated at any index which is unknown. Find the minimum element in the array.

Pre-requisites: Search in Rotated Sorted Array I,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Input: arr = [4,5,6,7,0,1,2,3]
Output: 0
Explanation: The minimum element in the array is 0.
Input : arr = [3,4,5,1,2]
Output: 1
Explanation : The minimum element in the array is 1.
*/

// mine same as sir logic
// eleminate the sorted half after storing its low as answer

#include<bits/stdc++.h>
using namespace std;

int find_min(vector<int>arr){
    int low=0, high=arr.size()-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }else{
            high=mid-1;
            ans=min(ans,arr[mid]);
        }
    }
    return ans;
}


int main() {
    // Example input
    vector<int> arr = {4,5,6,7,0,1,2,3};

    // Call the function and store result
    int rotations = find_min(arr);

    // Print result
    cout << rotations << endl;
    return 0;
}