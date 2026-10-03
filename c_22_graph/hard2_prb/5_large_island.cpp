#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to count one island after a candidate flip.
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();

        // Stop for invalid cells, water cells, and already counted cells.
        if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == 0 || visited[row][col] == 1) {
            return 0;
        }

        // Mark current land cell as counted.
        visited[row][col] = 1;

        // Count current cell and four neighboring directions.
        int area = 1;
        area += dfs(row - 1, col, grid, visited);
        area += dfs(row + 1, col, grid, visited);
        area += dfs(row, col - 1, grid, visited);
        area += dfs(row, col + 1, grid, visited);

        // Return island area for current DFS.
        return area;
    }

    // Function to compute largest island for the current grid.
    int largestCurrentIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int best = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Traverse every cell and count unvisited islands.
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1 && visited[row][col] == 0) {
                    best = max(best, dfs(row, col, grid, visited));
                }
            }
        }

        // Return largest island found.
        return best;
    }

public:
    // Function to find largest island by trying every zero flip.
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int answer = largestCurrentIsland(grid);
        bool hasZero = false;

        // Try every zero as a flip candidate.
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    hasZero = true;
                    grid[row][col] = 1;
                    answer = max(answer, largestCurrentIsland(grid));
                    grid[row][col] = 0;
                }
            }
        }

        // Return full grid size for all-land grid.
        if (!hasZero) {
            return n * n;
        }

        // Return best area after at most one flip.
        return answer;
    }
};

// Driver code.
int main() {
    vector<vector<int>> grid = {{1, 0}, {0, 1}};

    Solution sol;
    cout << sol.largestIsland(grid);
    return 0;
}
