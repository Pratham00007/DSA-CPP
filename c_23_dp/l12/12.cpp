#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the minimum falling path sum with a table.
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // The table stores one result for every matrix cell.
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // The last row supplies every recursive base state.
        for (int col = 0; col < n; col++) {
            dp[n - 1][col] = matrix[n - 1][col];
        }

        // Upward order keeps the next row ready for use.
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int downLeft = 1000000000;
                int down = dp[row + 1][col];
                int downRight = 1000000000;

                // A left diagonal exists beyond the first column.
                if (col > 0) {
                    downLeft = dp[row + 1][col - 1];
                }

                // A right diagonal exists before the last column.
                if (col + 1 < n) {
                    downRight = dp[row + 1][col + 1];
                }

                // The smallest child preserves the recurrence.
                int bestNext = min(
                    downLeft, min(down, downRight)
                );

                // The cell value extends the best child path.
                dp[row][col] = matrix[row][col] + bestNext;
            }
        }

        // Any first-row column may start the optimal path.
        return *min_element(dp[0].begin(), dp[0].end());
    }
};

// Driver code
int main() {
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    Solution obj;
    cout << obj.minFallingPathSum(matrix);
    return 0;
}