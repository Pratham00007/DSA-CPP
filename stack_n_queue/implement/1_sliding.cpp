/*
Sliding Window Maximum


4

Problem Statement: Given an array of integers arr, there is a sliding window of size k
 which is moving from the very left of the array to the very right. 
 You can only see the k numbers in the window. Each time the sliding window
  moves right by one position. Return the max sliding window..

Examples
Input: arr = [4,0,-1,3,5,3,6,8], k = 3
Output: [4,3,5,5,6,8]
Explanation: 

Window position                   Max
------------------------         -----
[4  0  -1] 3  5  3  6  8           4
 4 [0  -1  3] 5  3  6  8           3
 4  0 [-1  3  5] 3  6  8           5
 4  0  -1 [3  5  3] 6  8           5
 4  0  -1  3 [5  3  6] 8           6
 4  0  -1  3  5 [3  6  8]          8

For each window of size k=3, we find the maximum element in the window and 
add it to our output array.

Input: arr= [20,25], k = 2
Output: [25]
Explanation: There’s just one window is size 2 that is possible and the
 maximum of the two elements is our answer.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();

        deque<int>dq;
        vector<int>result;

        for(int i=0;i<n;i++){
            // removing from front if out of window size
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // remove from back if not useful
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            // adding front element to result when first winidow completed
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }

int main(){

}