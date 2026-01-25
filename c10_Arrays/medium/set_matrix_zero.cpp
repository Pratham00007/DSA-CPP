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

// brute force O(n3)
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


// beter tc(2*m*n) sc(m+n)

void zero2(vector<vector<int>>&arr){
    int m=arr.size();
    int n=arr[0].size();

    int row[m]={0};
    int col[n]={0};
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==1 || col[j]==1)
            arr[i][j]=0;
        }
    }
}

// optimal Sc=O(1) tc(P\O(n2))
void zero3(vector<vector<int>>&arr){
// int  col[m]= {0}; martrix[0][..]
// int row[0]={0}; martrix[..][0];
int n=arr.size(); // no of rows
int m=arr[0].size(); // no of columns
int col0=1;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(arr[i][j]==0){
            // mark ith row 
            arr[i][0]=0;
            
            // mark jth col
            if(j!=0){
                arr[0][j]=0;

            }
            else{
                col0=0;
            }
        }
    }
}
for (int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(arr[i][j]!=0){
            // check for col and row
            if(arr[0][j]==0||arr[i][0]==0){
                arr[i][j]=0;
            }
        }
    }
}

if(arr[0][0]==0){
    for(int j=0;j<m;j++){
        arr[0][j]=0;

    }
}
if (col0==0){
    for(int i=0;i<n;i++){
        arr[i][0]=0;
    }
}
}

int main(){
     // Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    zero3(matrix);
    
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;

}