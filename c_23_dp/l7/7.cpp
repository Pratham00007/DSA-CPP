#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the maximum merit points with tabulation.
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        // Four columns preserve every forbidden choice.
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Build the base row from valid first-day choices.
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0],
                       max(points[0][1], points[0][2]));

        // Move forward because every earlier row is ready.
        for (int day = 1; day < n; day++) {
            // Calculate all four forbidden-activity states.
            for (int last = 0; last < 4; last++) {
                // Try every activity because any choice can win.
                for (int activity = 0; activity < 3; activity++) {
                    // Skip repetition to keep the schedule valid.
                    if (activity != last) {
                        // Add the score to the matching prior state.
                        int candidate = points[day][activity]
                                      + dp[day - 1][activity];

                        // Keep the largest total for the state.
                        dp[day][last] = max(
                            dp[day][last], candidate
                        );
                    }
                }
            }
        }

        // Sentinel three represents no final restriction.
        return dp[n - 1][3];
    }
};

// Driver code
int main() {
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    Solution obj;
    cout << obj.ninjaTraining(points) << '\n';
    return 0;
}