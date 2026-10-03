#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Counts reachable vertices after skipping one edge.
    int reachableCount(int vertices, vector<vector<int>>& edges, int skippedEdge) {
        vector<vector<int>> adjacency(vertices);

        // Build the graph without the selected edge occurrence.
        for (int edgeId = 0; edgeId < static_cast<int>(edges.size()); edgeId++) {
            // Skip only the current edge occurrence.
            if (edgeId == skippedEdge) {
                continue;
            }

            int first = edges[edgeId][0];
            int second = edges[edgeId][1];

            adjacency[first].push_back(second);
            adjacency[second].push_back(first);
        }

        vector<bool> visited(vertices, false);
        stack<int> pending;

        // Start traversal from vertex zero.
        pending.push(0);
        visited[0] = true;

        int reached = 0;

        // Traverse the remaining graph from vertex zero.
        while (!pending.empty()) {
            int node = pending.top();
            pending.pop();

            // Count the current reachable vertex.
            reached++;

            // Visit all unvisited neighbors.
            for (int neighbor : adjacency[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    pending.push(neighbor);
                }
            }
        }

        // Return total reachable vertices.
        return reached;
    }

public:
    // Finds bridges by removing every edge once.
    vector<vector<int>> findBridges(int vertices, vector<vector<int>>& edges) {
        vector<vector<int>> bridges;

        // Remove each edge occurrence and test graph connectivity.
        for (int edgeId = 0; edgeId < static_cast<int>(edges.size()); edgeId++) {
            // If fewer vertices are reachable, the edge is a bridge.
            if (reachableCount(vertices, edges, edgeId) < vertices) {
                int first = min(edges[edgeId][0], edges[edgeId][1]);
                int second = max(edges[edgeId][0], edges[edgeId][1]);

                bridges.push_back({first, second});
            }
        }

        // Sort bridge endpoints for deterministic output.
        sort(bridges.begin(), bridges.end());

        return bridges;
    }
};

// Driver code.
int main() {
    int vertices = 5;

    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    };

    Solution solution;

    vector<vector<int>> bridges = solution.findBridges(vertices, edges);

    // Print every bridge edge.
    for (const auto& edge : bridges) {
        cout << "[" << edge[0] << "," << edge[1] << "] ";
    }

    return 0;
}