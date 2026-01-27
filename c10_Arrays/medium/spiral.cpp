/*
Spiral Traversal of Matrix



0

Problem Statement: Given a Matrix, print the given matrix in spiral order.

Examples
Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Input: Matrix[][] = { { 1, 2, 3 }, { 4, 5, 6 },{ 7, 8, 9 } }
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> spiral(vector<vector<int>>mat){
    int n=mat.size();
    int m=mat[0].size();
    int left=0,right=m-1;
    int top=0,bottom=n-1;
    vector<int>ans;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);

            }
            bottom--;

        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;

        }
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };
    vector<int> ans=spiral(arr);
    for (auto it:ans){
        cout<<it;
    }

}
