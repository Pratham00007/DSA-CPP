/*
Search in a row and column-wise sorted matrix


Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where
 'N' and 'M' denote the number of rows and columns, respectively. 
 The elements of each row and each column are sorted in non-decreasing order.
 But, the first element of a row is not necessarily greater than the last element of the 
 previous row (if it exists). You are given an integer ‘target’, 
 and your task is to find if it exists in the given 'mat' or not.

Examples
Example 1:
Matrix=
1   4   7   11
2   5   8   12
3   6   9   16
10 13  14  17
Target: 9
Output: Found at (2,2) (0-indexed)


Example 2:
Matrix=
5   10  15
6   12  18
8   16  20
Target: 7
Output: Not Found
*/

#include<bits/stdc++.h>
using namespace std;

// sir better - > bs on each row as row is also sorted
// sir optimal -> diagonally

bool sear(vector<vector<int>>mat, int target){
    int n=mat.size();
    int m=mat[0].size();
    int row=0, col=m-1;
    while(row<n && col>= 0){
        if(mat[row][col]==target)return true;
        else if(mat[row][col]<target) row++;
        else col--;
    }
    return false;
}