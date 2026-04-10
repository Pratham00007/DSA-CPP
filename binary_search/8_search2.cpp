/*
Search Element in Rotated Sorted Array II


16

Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

Examples
Example 1:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result: True
Explanation: The element 3 is present in the array. So, the answer is True.

Example 2:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result: False
Explanation: The element 10 is not present in the array. So, the answer is False.

*/

// mine just same as prev instaed of index return true

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>arr, int target){
    int n=arr.size();
    int l=0,h=n-1;
    

    while (l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==target){
            return true;
        }
        if(arr[l]<=arr[mid]){
            if(arr[l]<=target && arr[h]>=target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }else{
            if(target>=arr[mid] && target<=arr[h]){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        
    }
    return false;
    
}

// sir see the edge case in ss
// can't use the earlier way in that edge case 
// for that shrink the array

bool search2(vector<int>arr, int k){
    int n=arr.size();
    int l=0,h=n-1;
    while(l<=h){
        int mid=(h+l)/2;
        if(arr[mid]==k) return true;
        if(arr[l]==arr[mid] && arr[mid]==arr[h]){
            l++,h--;
            continue;
        }

        if(arr[l] <= arr[mid]){
            if(arr[l]<=k && k<=arr[mid]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }else{
            if(arr[mid]<=k && k<=arr[h]){
            l=mid+1;}else{
                h=mid-1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;

   
    bool ans = search2(arr, k);

    // Print result
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}