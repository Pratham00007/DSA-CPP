/*
Implement Pow(x,n) | X raised to the power N


Problem Statement: Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.

Examples
Example 1:
Input:
 x = 2.0000, n = 10  
Output:
 1024.0000  
Explanation:
 The answer is calculated as 2^10, which equals 1024.

Example 2:
Input:
 x = 2.0000, n = -2  
Output:
 0.2500  
Explanation:
 The answer is calculated as 2^(-2), which is equal to 1/4 = 0.25.
*/

// sir brute force normally * n times the same no to get ans
// optimal decompose power by inceasing number

#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    double ans=1.0;
    long long nn=n;
    if(nn<0) nn= -1*nn;
    while(nn){
        if(nn%2){
            ans=ans*x;
            nn=nn-1;

        }else{
            x=x*x;
            nn=nn/2;
        }
    }
    if(n<0) ans=(double)(1.0)/(double)(ans);
    return ans;
}