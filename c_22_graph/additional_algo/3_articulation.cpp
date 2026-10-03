#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to count components while ignoring one vertex.
    int countComponents(int vertices,
                        const vector<vector<int>>& adjacency,
                        int removedVertex) {
        vector<bool> visited(vertices, false);
        int components = 0;

        // Start traversal from every remaining unvisited vertex.
        for (int start = 0; start < vertices; start++) {
            if (start == removedVertex || visited[start]) continue;

            components++;
            stack<int> pending;
            pending.push(start);
            visited[start] = true;

            while (!pending.empty()) {
                int node = pending.top();
                pending.pop();

                for (int neighbor : adjacency[node]) {
                    if (neighbor != removedVertex && !visited[neighbor]) {
                        visited[neighbor] = true;
                        pending.push(neighbor);
                    }
                }
            }
        }
        return components;
    }

public:
    // Function to find articulation points by removing every vertex.
    vector<int> articulationPoints(int vertices,
                                   vector<vector<int>>& edges) {
        vector<vector<int>> adjacency(vertices);

        // Build the undirected adjacency list once.
        for (const auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }

        int originalComponents = countComponents(vertices, adjacency, -1);
        vector<int> answer;

        // Compare component counts after removing every candidate vertex.
        for (int removed = 0; removed < vertices; removed++) {
            int remainingComponents = countComponents(
                vertices, adjacency, removed
            );
            if (remainingComponents > originalComponents) {
                answer.push_back(removed);
            }
        }

        // Return -1 when no articulation point exists.
        if (answer.empty()) return {-1};
        return answer;
    }
};

// Driver function with a hard-coded undirected graph.
int main() {
    int vertices = 7;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {0, 3},
        {3, 4}, {4, 5}, {5, 3}, {5, 6}
    };

    Solution solution;
    vector<int> answer = solution.articulationPoints(vertices, edges);
    for (int node : answer) cout << node << " ";
    return 0;
}