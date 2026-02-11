/*
Length of the longest subarray with zero Sum



0

Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Examples
Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result:
 5  
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Example 2:
Input:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}  
Result:
 8  
Explanation:
 Subarrays with sum zero:
- {-2, 2}
- {-8, 1, 7}
- {-2, 2, -8, 1, 7}
- {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8.
*/

#include<bits/stdc++.h>
using namespace std;


// mine O(n2)
int zero1(vector<int>arr,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if (sum==0){
                ans=max(ans,j-i+1);

            }
        }
    }
    return ans;

}
int main(){
    int ans=zero1({6, -2, 2, -8, 1, 7, 4, -10},8);
    cout<<ans;
}