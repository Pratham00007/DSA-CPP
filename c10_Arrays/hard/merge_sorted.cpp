/*
Merge two Sorted Arrays Without Extra Space



12

Problem Statement: Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array sorted in non-decreasing order.
The final sorted array should be stored inside the array nums1 and it should be done in-place.
Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.

Examples
Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
Output : [-5, -3, -2, 1, 4, 5, 8]
Explanation : The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2
Input : nums1 = [0, 2, 7, 8, 0, 0, 0], nums2 = [-7, -3, -1]
Output :  [-7, -3, -1, 0, 2, 7, 8]
Explanation :  The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2
*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

// sir brute force-> using arr3
// optimal->shell sort gap method

void swapifGreater(long long arr1[],long long arr2[],int id1,int id2){
    if(arr1[id1]>arr2[id2]){
        swap(arr1[id1],arr2[id2]);
    }
}
void merge2(long long arr1[],long long arr2[],int n,int m) {
    int len=n+m;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            // arr1 and arr2
            if(left<n && right>=n){
                swapifGreater(arr1,arr2,left,right-n);
            }
            // arr2 and arr2
            else if(left>=n){
                swapifGreater(arr2,arr2,left-n,right-n);
            }
            // arr1 and arr1
            else{
                swapifGreater(arr1,arr1,left,right);
            }
            left++,right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}

// mine
// brute -> in place of zero insert nums2 elements then sort

    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m;
        int j=0;
        while(i<m+n){
            
            if(nums1[i]==0){            
            nums1[i]=nums2[j];
            i++;
            j++;
            }else{i++;}
        }
        sort(nums1.begin(),nums1.end());
        // cout<<endl;
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;

    Solution().merge1(nums1, m, nums2, n);

    // Print merged array
    for (int num : nums1) cout << num << " ";
    return 0;
}
