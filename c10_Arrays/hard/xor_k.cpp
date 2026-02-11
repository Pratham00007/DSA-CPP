/*
Count the number of subarrays with given xor K



0

Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

Examples
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Input: A = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/
#include<bits/stdc++.h>
using namespace std;

// sir
// brute O(n^3)
// better O(n^2) same as mine
// optimal 

// mine
int answ(vector<int> arr,int target){
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if((arr[i]^arr[j])==target){
                ans+=1;
            }
        }
    }
    return ans;
}

int main(){
    vector<int>arr1={4, 2, 2, 6, 4};
    
        cout<<answ(arr1,6);
    }

