/*
Nth Root of a Number using Binary Search


10

Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

Examples
Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.
Input : N = 4, M = 69
Output: -1
Explanation : The 4th root of 69 does not exist. So, the answer is -1.
*/

// mine go form 1 to n if  at any point the power get increased then return -1
// or if at any point power caused the equall to the number so return the number

// better  same like goes from mid to the power is at
// eliminate the half by checking mid

// brute mine

#include <bits/stdc++.h>
using namespace std;

int root(int n,int m){
    int ans=1;
    for (int i=1;i<m;i++){
        
        ans = pow(i,n);
        if (ans==m) return i;
        if (ans>m) return -1;
    }
}

// better mine

int root_bs(int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = (low + high) / 2;

        int val = (int)pow(mid, n);

        if (val == m) {
            return mid;
        }

        if (val > m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    cout << root(2, 16);
}