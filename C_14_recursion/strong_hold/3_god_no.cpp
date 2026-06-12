/*
Count Good numbers


6

Problem Statement: A digit string is considered good if the digits at even indices
 (0-based) are even digits (0, 2, 4, 6, 8) and the digits at odd indices are prime digits 
 (2, 3, 5, 7).

Given an integer n, return the total number of good digit strings of length n.
 As the result may be large, return it modulo 109 + 7.

A digit string is a string consisting only of the digits '0' through '9'. 
It may contain leading zeros.

Examples
Example 1:
Input:
 n = 1
Output:
 5
Explanation:
 Only one index (0) → must be even.
Valid strings: "0", "2", "4", "6", "8"

Example 2:
Input:
 n = 2
Output:
 20
Explanation:
 Index 0: 5 options (even digits)
Index 1: 4 options (prime digits)
Total: 5 * 4 = 20
*/

// except at n=1 at other n/2 are even digit rest primr so * accordingly


#include<bits/stdc++.h>
using namespace std;


// mine -> logic ans all good but compile error in leetcode
const int MOD = 1e9 + 7;
int good_no(int n){
    long long m=0,q=0,ans=0;
if(n%2!=0){
    m=n/2 +1;
    q=n-m;
}else{
    m=n/2;
    q=n-m;
}
if(q!=0)     ans=pow(5,m) * pow(4,q);
else ans=pow(5,m);
     return ans % MOD;

}



// rec appraoch sir works but time limit exceed

int cnt_good(int index,int n){
    if(n==index) return 1;

    int result=0;
    if(index%2==0){
        for(int  digit: {0,2,4,6,8}){
            result= (result + cnt_good(index+1,n))%MOD;
        }
    }else{
        for(int digit:{2,3,5,7}){
            result= (result + cnt_good(index+1,n))%MOD;
        }
    }

    return result;
}

// gpt to avoid the overflow and time limit issues
class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1) {              // current bit is 1
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;        // square the base
            b >>= 1;                  // divide exponent by 2
        }

        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2; // indices 0,2,4,...
        long long oddPos = n / 2;        // indices 1,3,5,...

        long long ans =
            (modPow(5, evenPos) * modPow(4, oddPos)) % MOD;

        return (int)ans;
    }
};

int main(){
    cout<<good_no(4);
}


