/*
Area of largest rectangle in Histogram


Problem Statement: Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1 return the area of the largest rectangle in histogram. .

Examples
Example:

Input: N =6, heights[] = {2,1,5,6,2,3}
Output: 10
*/

#include<bits/stdc++.h>
using namespace std;


int lar(vector<int>histo){
    stack<int> st; // Stack to store indices of the histogram bars
        int maxA = 0;  // Variable to keep track of the maximum area
        int n = histo.size();

        // Loop through each bar including an imaginary bar at the end
        for (int i = 0; i <= n; i++) {
            // While current bar is smaller than the top of the stack or we reached the end
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()]; // Get the height of the bar at top of the stack
                st.pop(); // Remove that bar

                int width;
                if (st.empty()) {
                    width = i; // All bars before were higher
                } else {
                    width = i - st.top() - 1; // Width between current index and index at top of stack
                }

                // Calculate area and update maximum area
                maxA = max(maxA, width * height);
            }
            // Push current index into stack
            st.push(i);
        }
        return maxA;
}

int main(){
    
}