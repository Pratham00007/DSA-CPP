/*
Floor and Ceil in Sorted Array


Problem Statement: ou're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x

Examples

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/


#include<bits/stdc++.h>
using namespace std;

// mine same brute O(n)
// better O(logn) logic if present then return same in both else upper bound and up-1

vector<int> ub(int arr[],int n, int target){
    
    int l=0,h=n-1;
    int ans=0;
    while(l<=h){
       int mid=(l+h)/2;
       if(arr[mid]>target){
        ans=mid;
        h=mid-1;
       }else{
        l=mid+1;
       }
    }

    if(arr[ans-1]==target){
        return {target,target};
    }
    return {arr[ans-1],arr[ans]};
}

// sir same lb

int main(){
    
    int arr[]={3, 4, 4, 7, 8, 10};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    vector<int>ans=ub(arr,n,5);
    for(auto it:ans){
        cout<<it<<" ";
    }
}