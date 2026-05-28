/*
Kth Missing Positive Number


Problem Statement: You are given a strictly increasing array ‘vec’ 
and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

Examples
Example 1:
Input Format: vec[]={4,7,9,10}, k = 1
Result: 1
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. 
Since 'k' is 1, the first missing element is 1.

Example 2:
Input Format: vec[]={4,7,9,10}, k = 4
Result: 5
Explanation: The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on.
 Since 'k' is 4, the fourth missing element is 5.
*/


#include <bits/stdc++.h>
using namespace std;

// SIR BRUTE FORCE
//  check the given number fro marray starting 
// if lesser number present +1 to the target because it means they are not missing so index will be increased

int ls(vector<int>arr,int k){
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=k){
            k++;
        }else{
            return k;
        }
    }
    return k;
}

// sir optimal

int bs(vector<int>arr, int k){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return k+high+1;
}

int main(){
    int ans=bs({4,7,9,10},4);
    cout<<ans;
}