/*
Find out how many times the array has been rotated


9

Problem Statement: Given an integer array arr of size N, 
sorted in ascending order (with distinct values). 
Now the array is rotated between 1 to N times which is unknown.
 Find how many times the array has been rotated.

Pre-requisites: Find minimum in Rotated Sorted Array, 
 Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Input : arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. 
So, we can notice that the array has been rotated 4 times.

Input : arr = [3,4,5,1,2]
Output : 3
Explanation: The original array should be [1,2,3,4,5].
 So, we can notice that the array has been rotated 3 times.
*/

// mine find lowest elemnt index - size of array


#include<bits/stdc++.h>
using namespace std;

int findRotations(vector<int>arr){
    int n=arr.size();
    int low=0, high=arr.size()-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[mid]){
            if(arr[ans]>arr[low]) ans=low;
            
            low=mid+1;
        }else{
            high=mid-1;
            if (arr[ans]>arr[mid]) ans=mid;
            
        }
    }
    return (n-ans) ;
}


int main() {

    // Example input
    vector<int> arr = {3,4,5,1,2};

    // Call the function and store result
    int rotations =findRotations(arr);

    // Print result
    cout << rotations << endl;
    return 0;
}