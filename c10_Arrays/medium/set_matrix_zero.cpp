/*
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix..

Examples
Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0

*/

#include <bits/stdc++.h>
using namespace std;

void zero1(vector<vector<int>>&arr){
    int m=arr.size(); // no of rows
    int n=arr[0].size(); // no of columns


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0){
                // marking row with -1
                for(int col=0;col<n;col++){
                    if(arr[i][col]!=0){
                        arr[i][col]=-1;
                    }
                }
                // mark col with -1
                for(int row=0;row<m;row++){
                    if (arr[row][j]!=0){
                        arr[row][j]=-1;
                    }
                }
            }

        }
        
    }

    // replace all-1 with 0 now
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
    
}


int main(){
     // Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    zero1(matrix);
    
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;

}