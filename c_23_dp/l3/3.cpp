#include<bits/stdc++.h>
using namespace std;


int minCost(int height[], int n) {
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev+abs(height[i]-height[i-1]);
        int ss=INT_MAX;
        if(i>1) ss=prev2+abs(height[i]-height[i-2]);

        
    int curi=min(fs,ss);
    prev2=prev;
    prev=curi;
    }

    return prev;

    
}

int main(){

}