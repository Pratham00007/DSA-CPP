#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Computes the minimum energy required to reach one stone.
    int solve(int index, vector<int>& heights, int k) {
        // The starting stone needs no jump.
        if (index == 0) {
            return 0;
        }

        int minimumEnergy = INT_MAX;

        // Every allowed previous stone is tested as the jump source.
        for (int jump = 1; jump <= k; jump++) {
            int previousIndex = index - jump;

            // A jump can be used only when the previous stone exists.
            if (previousIndex >= 0) {
                int difference = abs(heights[index] - heights[previousIndex]);
                // A predecessor answer covers energy to the source.
                // The height difference adds the final jump cost.
                int jumpEnergy = solve(previousIndex, heights, k) + difference;
                minimumEnergy = min(minimumEnergy, jumpEnergy);
            }
        }

        return minimumEnergy;
    }

public:
    // Returns minimum energy for the final stone.
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return solve(n - 1, heights, k);
    }
};

// Driver code
int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;
    Solution obj;
    cout << obj.frogJump(heights, k) << endl;
    return 0;
}