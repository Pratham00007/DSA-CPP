#include<bits/stdc++.h>
using namespace std;

int min_path_sum(vector<vector<int>>&traingle,int n){
    vector<int>front(n,0),cur(n,0);
    for(int j=0;j<n;j++) front[j]=traingle[n-1][j];
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=traingle[i][j]+front[j];
            int dg=traingle[i][j]+ front[j+1];
            cur[j]=min(d,dg);
        }
        front=cur;
    }
    return front[0];
}

int main(){

}