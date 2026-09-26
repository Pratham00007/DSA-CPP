#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Return shortest weight followed by the path from 1 to n.
    vector<long long> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);

        // Build an undirected weighted adjacency list.
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        const long long INF = numeric_limits<long long>::max() / 4;
        vector<long long> dist(n + 1, INF);
        vector<int> parent(n + 1);

        // Initialize every vertex as its own parent.
        for (int vertex = 1; vertex <= n; vertex++) {
            parent[vertex] = vertex;
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > minHeap;

        // Start Dijkstra traversal from vertex 1.
        dist[1] = 0;
        minHeap.push({0, 1});

        // Process vertices in increasing known distance.
        while (!minHeap.empty()) {
            auto [currentDistance, node] = minHeap.top();
            minHeap.pop();

            // Skip an outdated heap entry.
            if (currentDistance != dist[node]) {
                continue;
            }

            // Stop after destination distance becomes final.
            if (node == n) {
                break;
            }

            // Relax every edge leaving the selected vertex.
            for (const auto& [neighbor, weight] : adj[node]) {
                long long candidate = currentDistance + weight;

                // Record a better distance and predecessor.
                if (candidate < dist[neighbor]) {
                    dist[neighbor] = candidate;
                    parent[neighbor] = node;
                    minHeap.push({candidate, neighbor});
                }
            }
        }

        // Return failure after an unreachable destination.
        if (dist[n] == INF) {
            return {-1};
        }

        vector<long long> path;
        int node = n;

        // Follow predecessor links from destination to source.
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);

        // Reverse path into source-to-destination order.
        reverse(path.begin(), path.end());

        vector<long long> answer;

        // Store shortest weight first.
        answer.push_back(dist[n]);

        // Store path vertices after the weight.
        answer.insert(answer.end(), path.begin(), path.end());

        return answer;
    }
};

// Driver code.
int main() {
    int n = 5;
    int m = 6;

    vector<vector<int>> edges = {
        {1, 2, 2}, {2, 5, 5}, {2, 3, 4},
        {1, 4, 1}, {4, 3, 3}, {3, 5, 1}
    };

    Solution sol;

    vector<long long> answer = sol.shortestPath(n, m, edges);

    // Print shortest weight followed by path vertices.
    for (long long value : answer) {
        cout << value << " ";
    }

    return 0;
}