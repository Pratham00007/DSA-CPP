/*
Find Peak Element (2D Matrix)


4

Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal,
 find any peak element mat[i][j] and return the array [i, j]. A peak element in a 2D grid 
 is an element that is strictly greater than all of its adjacent neighbours to the 
 left, right, top, and bottom.
Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

Note: As there can be many peak values, 1 is given as output if the returned index is a peak number,
otherwise 0.

Examples
Example 1:
Input:
 mat = [[5, 10, 8], [4, 25, 7], [3, 9, 6]]
Output:
 [1, 1]
Explanation:
 The value at index [1, 1] is 25, which is a peak because all its neighbors (10, 7, 4, 9) are smaller.

Example 2:
Input:
 mat = [[1, 2, 3], [6, 5, 4], [7, 8, 9]]
Output:
 [2, 2]
Explanation:
 The value at index [2, 2] is 9, which is a peak as it is greater than its neighbors (8, 4).
*/



#include<bits/stdc++.h>
using namespace std;