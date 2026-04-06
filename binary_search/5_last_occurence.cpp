/*
Last occurrence in a sorted array

Problem Statement: Given a sorted array of N integers, write a program to find 
the index of the last occurrence of the target key. If the target is not found then return -1. 
Note: Consider 0 based indexing

Examples
Example 1:
Input:
 N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40}  
Output:
 4  
Explanation:
 The target value 13 appears for the first time at index number 2 in the array.  

Example 2:
Input:
 N = 7, target = 60, array[] = {3, 4, 13, 13, 13, 20, 40}  
Output:
 -1  
Explanation:
 Target value 60 is not present in the array, so the output is -1.

*/

#include <bits/stdc++.h>
using namespace std;


// mine find ub-1 for last and for first occurenece lb
int l_index(vector<int>arr, int target)
{
    int n=arr.size();
    int l=0,h=n-1;
    int ans=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]>target){
            ans=mid-1;
            h=mid-1;
        }else{            
            l=mid+1;
        }
    }
    return ans;
}


// sir brite linear search and optimal ->same used different up and lb func 
// O(2logn)

int main(){
    vector<int>arr={3, 4, 13, 13, 13, 20, 40};
    cout<<l_index(arr,13);

}