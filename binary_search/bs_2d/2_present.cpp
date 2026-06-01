/*
Search in a sorted 2D matrix


10

Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

Examples
Input :mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
Output :True.
Explanation :The target = 8 exists in the 'mat' at index (1, 3).

Input :mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78
Output :false.
Explanation :The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.
*/

// mine bs on each row for element
// sir see if target in between the that row of matrrix then give that row for bs
// tc O(n) + O(log m)

// sir hypothetical 1d matrix

#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>mat,int target){
    int n=mat.size();
    int m=mat[0].size();
    int low=0,high=n*m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;

        if(mat[row][col]==target) return true;
        else if(mat[row][col]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}