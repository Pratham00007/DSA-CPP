/*
Minimum days to make M bouquets


12

Problem Statement: You are given 'N’ roses and you are also given an array 'arr'
where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
You can only pick already bloomed roses that are adjacent to make a bouquet.
You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses.
Return -1 if it is not possible.

Examples
Example 1:
Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
Result: 12
Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed.
So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

Example 2:
Input Format: N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
Result: -1
Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. 
But we are given only 5 flowers, so, we cannot make the bouquets.
*/

/*
sir brute force

go from min to max
and see if on the given no bloomed add counter 
and when not bloomed then add to bouque by k/cnt
and cnt=0 again

till reach the end do
do from min to max in array

*/

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> arr, int day, int m , int k){
    int cnt=0, noBou=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            noBou+=(cnt/k);
            cnt=0;
        }
    }
    noBou+=(cnt/k); //when reached at last
    if(noBou>=m) return true;
    else {return false;}
}
int lin(){
    vector<int>arr={7,7,7,7,13,11,12,7};
    int m=2, k=3;
    int mini=arr[0];
    int maxi=arr[0];
    int n=arr.size();
    for (int i=0;i<n;i++){
    if (arr[i]<mini){
        mini=arr[i];
    }
    if(arr[i]>maxi){
        maxi=arr[i];
    }
    }
    if(n<m*k) {return -1;}
    for(int i=mini;i<maxi;i++){
        if(possible(arr,i,m,k)==true){
            return i;
        }
        
    }
    return-1;
}

/*
sir optiomal

use the binary by see from min to max creqate array
see if at mid not possible so go to right half array part 

*/

int bs(){
     vector<int>arr={7,7,7,7,13,11,12,7};
    int m=2, k=3;
    int mini=arr[0];
    int maxi=arr[0];
    int n=arr.size();
    for (int i=0;i<n;i++){
    if (arr[i]<mini){
        mini=arr[i];
    }
    if(arr[i]>maxi){
        maxi=arr[i];
    }
    }

    // leetcode overflow even long long doesnt work
    
    // if(n<m*1LL*k*1LL) return -1;
    if(n<m*k) return -1;
    int low=mini;
    int high=maxi;
    int ans=low;
    while(low<=high){
        int mid=(low+high)/2;
        int ans1=possible(arr,mid,m,k);
        if (ans1==false){
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=mid;
        }
    }
    return ans;
}


int main(){
    cout<<bs();
}

