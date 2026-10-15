#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the path count through tabulation.
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Processes cells after predecessor states are ready.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Keeps every blocked state unreachable.
                if (grid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }

                // Initializes the only path at the starting cell.
                if (row == 0 && col == 0) {
                    dp[row][col] = 1;
                    continue;
                }

                int fromAbove = 0;
                int fromLeft = 0;

                // Reads the predecessor above only inside the grid.
                if (row > 0) {
                    fromAbove = dp[row - 1][col];
                }

                // Reads the predecessor left only inside the grid.
                if (col > 0) {
                    fromLeft = dp[row][col - 1];
                }

                // Adds both valid predecessor groups.
                dp[row][col] = fromAbove + fromLeft;
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

// Driver code
int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution obj;

    cout << obj.uniquePathsWithObstacles(grid);
    return 0;
}