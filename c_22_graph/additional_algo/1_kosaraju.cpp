#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to record vertices after complete DFS exploration.
    void recordFinishOrder(int start,
                           const vector<vector<int>>& adjacency,
                           vector<bool>& visited,
                           vector<int>& finishOrder) {
        // Store {vertex, next neighbor index} as an explicit DFS frame.
        stack<pair<int, int>> frames;
        frames.push({start, 0});
        visited[start] = true;

        while (!frames.empty()) {
            int node = frames.top().first;
            int& nextIndex = frames.top().second;

            // Explore the next unvisited outgoing neighbor.
            if (nextIndex < static_cast<int>(adjacency[node].size())) {
                int neighbor = adjacency[node][nextIndex++];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    frames.push({neighbor, 0});
                }
                continue;
            }

            // Record the vertex only after every neighbor finishes.
            finishOrder.push_back(node);
            frames.pop();
        }
    }

    // Function to mark one SCC in the transpose graph.
    void markComponent(int start,
                       const vector<vector<int>>& transpose,
                       vector<bool>& visited) {
        stack<int> pending;
        pending.push(start);
        visited[start] = true;

        while (!pending.empty()) {
            int node = pending.top();
            pending.pop();

            // Traverse every reversed edge inside the current SCC.
            for (int neighbor : transpose[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    pending.push(neighbor);
                }
            }
        }
    }

public:
    // Function to count strongly connected components with Kosaraju's algorithm.
    int kosaraju(int vertices, vector<vector<int>>& edges) {
        vector<vector<int>> adjacency(vertices);
        vector<vector<int>> transpose(vertices);

        // Build both the original graph and the edge-reversed graph.
        for (const auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            transpose[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(vertices, false);
        vector<int> finishOrder;

        // Cover every DFS tree in the original directed graph.
        for (int node = 0; node < vertices; node++) {
            if (!visited[node]) {
                recordFinishOrder(node, adjacency, visited, finishOrder);
            }
        }

        fill(visited.begin(), visited.end(), false);
        int componentCount = 0;

        // Process vertices from largest finish time to smallest.
        for (int index = vertices - 1; index >= 0; index--) {
            int node = finishOrder[index];
            if (!visited[node]) {
                componentCount++;
                markComponent(node, transpose, visited);
            }
        }

        // Return the number of strongly connected components.
        return componentCount;
    }
};

// Driver function with a hard-coded directed graph.
int main() {
    int vertices = 5;
    vector<vector<int>> edges = {
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}
    };

    Solution solution;
    cout << solution.kosaraju(vertices, edges) << "\n";
    return 0;
}