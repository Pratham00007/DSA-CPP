#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Return minimum moves from source to destination in a binary maze.
    int shortestPath(vector<vector<int>>& grid,
                     pair<int, int> source,
                     pair<int, int> destination) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Reject a blocked source or destination.
        if (grid[source.first][source.second] == 0 ||
            grid[destination.first][destination.second] == 0) {
            return -1;
        }

        // Equal endpoints require zero moves.
        if (source == destination) {
            return 0;
        }

        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        // Start BFS at distance zero.
        dist[source.first][source.second] = 0;
        q.push(source);

        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};

        // Explore walkable cells in increasing distance order.
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // Check all four orthogonal neighbors.
            for (int direction = 0; direction < 4; direction++) {
                int nextRow = row + dRow[direction];
                int nextCol = col + dCol[direction];

                // Skip cells outside maze boundaries.
                if (nextRow < 0 || nextRow >= rows ||
                    nextCol < 0 || nextCol >= cols) {
                    continue;
                }

                // Skip blocked or previously visited cells.
                if (grid[nextRow][nextCol] == 0 ||
                    dist[nextRow][nextCol] != -1) {
                    continue;
                }

                int nextDistance = dist[row][col] + 1;
                dist[nextRow][nextCol] = nextDistance;

                // First destination discovery gives minimum distance.
                if (nextRow == destination.first &&
                    nextCol == destination.second) {
                    return nextDistance;
                }

                q.push({nextRow, nextCol});
            }
        }

        // Queue exhaustion means destination is unreachable.
        return -1;
    }
};

// Driver code.
int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};
    Solution sol;
    cout << sol.shortestPath(grid, source, destination);
    return 0;
}