/*
Print Prime Factors of a Number


Problem Statement: You are given an integer array queries of length n.
Return the prime factorization of each number in array queries in sorted order.

Examples
Example 1:
Input :
 queries = [2, 3, 4, 5, 6]
Output :
 [ [2], [3], [2, 2], [5], [2, 3] ]
Explanation :
 The values 2, 3, 5 are itself prime numbers.
The prime factorization of 4 will be 2 * 2.
The prime factorization of 6 will be 2 * 3.

Example 2:
Input :
 queries = [7, 12, 18]
Output :
 [ [7], [2, 2, 3], [2, 3, 3] ]
Explanation :
 The value 7 itself is a prime number.
The prime factorization of 12 will be 2 * 2 * 3.
The prime factorization of 18 will be 2 * 3 * 3.

*/


#include <bits/stdc++.h>
using namespace std;
vector<int>factors(int n){
    vector<int>factors_no;

    while(n%2==0){
        factors_no.push_back(2);
        n=n/2;
    }

    for(int i=3 ; i<=sqrt(n);i+=2){
        while(n%i==0){
            factors_no.push_back(i);
            n=n/i;
        }
    }

    if(n>2) factors_no.push_back(n);
    return factors_no;
}

vector<vector<int>>pf(vector<int>arr){
    vector<vector<int>>ans;
    for(auto it:arr){
        vector<int>temp=factors(it);
        ans.push_back(temp);
    }
    return ans;
}


int main() {
    vector<int> queries = {2, 3, 4, 5, 6};
    
    
    vector<vector<int>> ans = pf(queries);
    
    cout << "The prime factorization of all the numbers is: " << endl;
    for(int i=0; i < ans.size(); i++) {
        cout << "For " << queries[i] << ": "; 
        for(int j=0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}