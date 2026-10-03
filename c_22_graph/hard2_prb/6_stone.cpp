#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the maximum number of stones that can be removed.
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n, 0);
        int components = 0;

        // Each unvisited stone starts a new connected component.
        for (int start = 0; start < n; start++) {
            // This stone is already part of an earlier component.
            if (visited[start]) {
                continue;
            }

            components++;
            stack<int> pending;
            pending.push(start);
            visited[start] = 1;

            // DFS collects all stones connected by shared rows or columns.
            while (!pending.empty()) {
                int current = pending.top();
                pending.pop();

                // Compare the current stone with every other stone.
                for (int candidate = 0; candidate < n; candidate++) {
                    bool sharesRow = stones[current][0] == stones[candidate][0];
                    bool sharesColumn = stones[current][1] == stones[candidate][1];

                    // An unseen stone sharing a row or column belongs to this component.
                    if (!visited[candidate] && (sharesRow || sharesColumn)) {
                        visited[candidate] = 1;
                        pending.push(candidate);
                    }
                }
            }
        }

        // One stone must remain in each connected component.
        return n - components;
    }
};

// Driver code
int main() {
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0},
        {1, 2}, {2, 1}, {2, 2}
    };

    // instance for class Solution
    Solution sol;
    cout << sol.removeStones(stones);

    return 0;
}