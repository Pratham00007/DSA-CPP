#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();

               vector<vector<bool>> dp(
                   n,
                   vector<bool>(target + 1, false)
               );

               for (int index = 0; index < n; index++) {
                   dp[index][0] = true;
               }

               if (arr[0] <= target) {
                   dp[0][arr[0]] = true;
               }

               for (int index = 1; index < n; index++) {
                   for (int sum = 1; sum <= target; sum++) {
                       bool notTaken = dp[index - 1][sum];

                       bool taken = false;

                       if (arr[index] <= sum) {
                           taken = dp[index - 1][sum - arr[index]];
                       }

                       dp[index][sum] = taken || notTaken;
                   }
               }

               return dp[n - 1][target];
        
    }
};