/*
Search Insert Position



Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

Examples
Example 1:
Input Format: arr[] = {1,2,4,7}, x = 6
Result: 3
Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

Example 2:
Input Format: arr[] = {1,2,4,7}, x = 2
Result: 1
Explanation: 2 is present in the array and so we will return its index i.e. 1.
*/

#include<bits/stdc++.h>
using namespace std;

/*
mine
brute force-> O(n) jsut linear search
better-> O(logn) binary search by lower bound
*/

int lb(vector<int>arr, int target){
    int n=arr.size();
    int l=0,h=n-1;
    
    int ans=n;

    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]>=target){
            ans=mid;
            h=mid-1;

        }else{
            l=mid+1;
        }
    }
    return ans;
    
}

// sir lb as ans 

int main(){
    vector<int>arr={1,2,4,7};
    cout<<lb(arr,2);
}