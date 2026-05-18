/*
Search Single Element in a sorted array


Problem Statement: Given an array of N integers. Every number in the array except one appears twice.
Find the single number in the array.

Examples
Input : arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Output: 4
Explanation: Only the number 4 appears once in the array.

Input: arr[] = {1,1,3,5,5}
Output : 3
Explanation: Only the number 3 appears once in the array.
*/

// mine brute linear
// sir brute match arr[n] with the arr n-1 and arr n+1
// if any of it is equall to arr[i] then go to next else that is the answer

// better -> elplaination.md

#include <bits/stdc++.h>
using namespace std;


int single(vector<int> arr){
    int n=arr.size();
    // if arr size is 1
    if (n==1) return arr[0];
    // check for 0 index
    if (arr[0]!=arr[1])return arr[0];
    // check for last index
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid=(high+low)/2;
        if (arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
            return arr[mid];
        }

        // to see if we are in left half of single by seeing the index of dublicate element
        // if dublicate element pair are like even,odd so we are on left side else on right side

        // left side check
        if(n%2==1 && arr[mid]==arr[mid-1] || n%2==0 && arr[mid]==arr[mid+1]){
            low=mid+1;
        }else{
            high=mid-1;
        }

    }
    return -1;
}
int main(){
    cout<<single({1,1,2,2,3,3,4,5,5,6,6});
}