/*
Find the repeating and missing numbers



18

Problem Statement: Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

Note: You are not allowed to modify the original array.

Examples
Example 1:
Input:
 nums = [3, 5, 4, 1, 1]  
Output:
 [1, 2]  
Explanation:
 1 appears twice in the array, and 2 is missing from the array. So the output is [1, 2].

Example 2:
Input:
 nums = [1, 2, 3, 6, 7, 5, 7]  
Output:
 [7, 4]  
Explanation:
 7 appears twice in the array, and 4 is missing from the array. So the output is [7, 4].
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>mis(vector<int>arr){
    int n=arr.size();
    vector<int>ans={-1,-1};
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            ans[0]=arr[i];
        }
        if(arr[i]!=arr[i+1] && arr[i]+1 != arr[i+1]){
            ans[1]=arr[i]+1;
        }
    }
return ans;
}
int main(){
vector<int> nums = {3, 5, 4, 1, 1};
    
    // Create an instance of Solution class
    

    vector<int> result = mis(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}