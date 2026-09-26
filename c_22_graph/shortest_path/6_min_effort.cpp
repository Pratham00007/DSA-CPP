#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Check destination reachability under an effort limit.
    bool canReach(vector<vector<int>>& heights, int limit) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;

        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};

        // Explore every cell reachable within the limit.
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if (row == rows - 1 && col == cols - 1) {
                return true;
            }

            // Check all four neighboring cells.
            for (int direction = 0; direction < 4; direction++) {
                int nextRow = row + dRow[direction];
                int nextCol = col + dCol[direction];

                if (nextRow < 0 || nextRow >= rows ||
                    nextCol < 0 || nextCol >= cols ||
                    visited[nextRow][nextCol]) {
                    continue;
                }

                int difference = abs(
                    heights[row][col] - heights[nextRow][nextCol]
                );
                if (difference <= limit) {
                    visited[nextRow][nextCol] = 1;
                    q.push({nextRow, nextCol});
                }
            }
        }

        return false;
    }

public:
    // Return minimum possible maximum adjacent height difference.
    int minimumEffortPath(vector<vector<int>>& heights) {
        int minimumHeight = heights[0][0];
        int maximumHeight = heights[0][0];

        // Find a guaranteed upper bound for effort.
        for (const vector<int>& row : heights) {
            for (int height : row) {
                minimumHeight = min(minimumHeight, height);
                maximumHeight = max(maximumHeight, height);
            }
        }

        // Test effort limits from smallest to largest.
        for (int limit = 0; limit <= maximumHeight - minimumHeight; limit++) {
            if (canReach(heights, limit)) {
                return limit;
            }
        }

        return 0;
    }
};

// Driver code.
int main() {
    vector<vector<int>> heights = {
        {1, 2, 2}, {3, 8, 2}, {5, 3, 5}
    };
    Solution sol;
    cout << sol.minimumEffortPath(heights);
    return 0;
}