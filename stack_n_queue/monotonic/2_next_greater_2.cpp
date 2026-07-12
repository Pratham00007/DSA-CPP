/*

Track
Command Palette
Search for a command to run...

Blog
Discussion
YouTube
Next Greater Element - 2


4

Problem Statement: Given a circular integer array arr, return the next greater element for every element in arr.
The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner.
If it doesn't exist, return -1 for that element element.

Examples
Example 1:
Input:
 arr = [3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9]
Output:
 [10, -1, 6, 6, 2, 6, 7, 7, 9, 9, 10]
Explanation:
 For the first element in arr i.e, 3, the greater element which comes next to it 
 while traversing and is closest to it is 10. Hence,10 is present on index 0 
 in the resultant array. Now for the second element i.e, 10, there is 
 no greater number and hence -1 is it’s next greater element (NGE). 
 Similarly, we got the NGEs for all other elements present in arr.

Example 2:
Input:
 arr = [5, 7, 1, 7, 6, 0]
Output:
 [7, -1, 7, -1, 7, 5]
Explanation:
 For the first element in arr i.e, 5, the greater element which 
 comes next to it while traversing and is closest to it is 7. 
 Now for the second element i.e, 7, there is no greater number 
 and hence -1 is it’s next greater element (NGE). Similarly, 
 we got the NGEs for all other elements present in arr.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nge;
        stack<int>st;
        int n=nums.size();
        for(int i=2*n-1;i>=0;--i){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                nge.push_back(st.empty() ? -1 : st.top());
            }
            st.push(nums[i%n]);
        }
        reverse(nge.begin(),nge.end());
        return nge;
    }

int main(){

}