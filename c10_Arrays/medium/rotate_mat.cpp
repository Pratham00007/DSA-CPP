#include<bits/stdc++.h>
using namespace std;

// brute tc: n2 sc n2
vector<vector<int>> rotate1(vector<vector<int>>arr){
    // always come square mat but still
    int n=arr.size();
    
    vector<vector<int>> ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-i-1]=arr[i][j];
        }
    }
    return ans;
}

// better-> transpose and rotate
vector<vector<int>> rotate2(vector<vector<int>>arr){
    // always come square mat but still
    int n=arr.size();
    // transpose
    // tc: n/2*n/2
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    // reverse
    // tc= n*n/2
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }

    return arr;

} 
int main(){
     // Example matrix
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    
    vector<vector<int>> answer=rotate2(matrix);
    
    // Print final matrix
    for (auto row : answer) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}