/*
Sieve of Eratosthenes


0

Problem Statement: You are given an 2D array queries of dimension n*2.
The queries[i] represents a range from queries[i][0] to queries[i][1] (include the end points).

Return the count of prime numbers present in between each range in queries array.

Examples
Example 1:
Input:
 queries = [ [2, 5], [4, 7] ]  
Output:
 [3, 2]  
Explanation:
  
The range 2 to 5 contains three prime numbers: 2, 3, 5.  
The range 4 to 7 contains two prime numbers: 5, 7.

Example 2:
Input:
 queries = [ [1, 7], [3, 7] ]  
Output:
 [4, 3]  
Explanation:
  
The range 1 to 7 contains four prime numbers: 2, 3, 5, 7.  
The range 3 to 7 contains three prime numbers: 3, 5, 7.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>prime_lr(vector<vector<int>>&queries){
    if(queries.empty()) return {};

    int maxi=0;
    for(const auto& it:queries){
        maxi=max(maxi,it[1]);
    }

    vector<bool>isPrime(maxi+1,true);
    isPrime[0] = isPrime[1]=false;

    for(int p=2;p*p<=maxi;++p){
        if(isPrime[p]){
            for(int i=p*p;i<=maxi;i+=p){
                isPrime[i]=false;
            }
        }
    }

    std::vector<int> primeCount(maxi + 1, 0);
        for (int i = 1; i <= maxi; ++i) {
            primeCount[i] = primeCount[i - 1];
            if (isPrime[i]) {
                primeCount[i]++;
            }
        }

        // Step 3: Process each query to find the number of primes 
        // in the given range
        std::vector<int> result;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == 0) {
                result.push_back(primeCount[end]);
            } else {
                result.push_back(primeCount[end] - primeCount[start - 1]);
            }
        }

        return result;

}