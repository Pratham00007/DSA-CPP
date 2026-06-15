/*
N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle


4

Problem Statement: The n-queens is the problem of placing n queens on n × n 
chessboard such that no two queens can attack each other. Given an integer n, 
return all distinct solutions to the n -queens puzzle. Each solution contains a 
distinct boards configuration of the queen's placement, where ‘Q’ and ‘.’ indicate 
queen and empty space respectively.

Examples
Input: N = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown below

Input : N = 1
Output: [["Q"]]
Explanation : There is only one way to place 1 queen on 1x1 chessboard.
*/
#include <bits/stdc++.h>
using namespace std;
void solve(int col, vector<string>&board,int n, vector<int>&leftRow,
    vector<int>&upperDiagonal,vector<int>&lowerDiagonal,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+ col - row]==0){
                board[row][col]='Q';

                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;


                solve(col+1,board,n,leftRow,upperDiagonal,lowerDiagonal,ans);

                // backtrasckiong to remove queen
                board[row][col]='.';

                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;


            }
        }
}

vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
