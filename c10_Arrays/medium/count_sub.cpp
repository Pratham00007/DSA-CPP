/*
Count Subarray sum Equals K

Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k. A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
Output: 2
Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Input: N = 3, array[] = {1,2,3}, k = 3
Output: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
*/


#include <bits/stdc++.h>
using namespace std;

// sir
// brute O(n3) just mine + one more loop till j again
// better same as mine O(n2)
// optimal O(n) sc:O(n)

int subarr3(int n,int arr[],int k){
    map<int,int> mpp;
    int cnt=0,prefix_sum=0;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        prefix_sum+=arr[i];
        int remove=prefix_sum-k;
        cnt+=mpp[remove];
        mpp[prefix_sum]+=1;

    }
    return cnt;
}   


// mine
int subarr(int n,int arr[],int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                cnt++;
            }

        }
        
    }
    return cnt;
}


// trying two pointer approach

int subarr2(int n,int arr[],int k){
    int i=0,j=0;
    int sum=0;
    int cnt=0;
    while(j<n){
        if (sum==k){
            cnt++;
        }
        while(sum>k){
            sum=sum-arr[i];
            i++;
        }
        
        sum+=arr[j];
        j++;
        
    }
    return cnt;
}


int main(){
    int arr[10]={3, 1, 2, 4};
    cout<<subarr3(4,arr,6);
}