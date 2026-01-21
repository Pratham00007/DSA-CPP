/*

Longest Consecutive Sequence in an Array

Problem Statement: Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Examples
Example 1:
Input:
 nums = [100, 4, 200, 1, 3, 2]  
Output:
 4  
Explanation:
 The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:
Input:
 nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output:
 9  
Explanation:
 The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.

 */

 // all right to it are smaller then that no is leader 

#include<bits/stdc++.h>
using namespace std;


// mine

int subsequent(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    int maxi=0;
    arr.push_back(INT_MAX);
    n=n+1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]+1){
            maxi=max(maxi,i-maxi);
        }
    }
    return maxi;
}


int main(){
    cout<<"enter no of elements:"; 
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<subsequent(arr,n);
    
    
}
