/*
Median of Row Wise Sorted Matrix


Problem Statement:
Given a row-wise sorted matrix of size M*N, where M is no. of rows and N is 
no. of columns, find the median in the given matrix.
Note: M*N is odd.

Examples
Input: M = 3, N = 3, matrix[][] =

1 4 9 
2 5 6
3 8 7
Output: 5
Explanation: 
If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. Therefore, median = 5

Input: M = 3, N = 3, matrix[][] =

1 3 8 
2 3 4
1 2 5
Output: 3
Explanation: 
If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. Therefore, median = 3.
*/


#include<bits/stdc++.h>
using namespace std;

int ub(vector<int>arr,int x,int n){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int countsmallequal(vector<vector<int>>mat,int n, int m, int x){
int cnt=0;
for(int i=0;i<n;i++){
    cnt+=ub(mat[i],x,m);
}
return cnt;
}

int median(vector<vector<int>>mat, int m, int n){
    int low=INT_MAX, high=INT_MIN;
    n=mat.size();
    m=mat[0].size();
    for(int i=0;i<n;i++){
        low=min(low,mat[i][0]);
        high=max(high,mat[i][m-1]);
    }

    int req=(n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int smallEquall=countsmallequal(mat,n,m,mid);
        if(smallEquall <= req) low=mid+1;
        else high=mid-1;
    }
    return low;
}