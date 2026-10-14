#include<bits/stdc++.h>
using namespace std;

// using extra space dp

int fib(int n, vector<int>&dp){
    if(n<=1) return n;
    if( dp[n] != -1) return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int main(){
    int n=5;
    int prev=0;
    int curr=1;
    for(int i=2;i<=n;i++){
        int next=prev+curr;
        prev=curr;
        curr=next;
    }
    // return prev;


    // dp
    
    vector<int>dp(n+1,-1);
    cout<<fib(5,dp);
}