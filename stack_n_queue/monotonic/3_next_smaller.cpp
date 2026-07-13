/*
Next Smaller Element


5

Problem Statement: Given an array of integers arr, your task is 
to find the Next Smaller Element (NSE) for every element in the array.
The Next Smaller Element for an element x is defined as the first
 element to the right of x that is smaller than x.
If there is no smaller element to the right, then the NSE is -1.

Examples
Example 1:
Input:
 arr = [4, 8, 5, 2, 25]
Output:
 [2, 5, 2, -1, -1]
Explanation:

- For 4, the next smaller element is 2.
- For 8, the next smaller element is 5.
- For 5, the next smaller element is 2.
- For 2, there is no smaller element to its right → -1.
- For 25, no smaller element exists → -1.

Example 2:
Input:
 arr = [10, 9, 8, 7]
Output:
 [9, 8, 7, -1]
Explanation:

Each element’s next right neighbor is smaller.
Each element’s next right neighbor is smaller.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>less_val(vector<int>arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n,-1);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(!st.empty()){ 
            ans[i]=st.top();

        }
        st.push(arr[i]);
    }
return ans;
}

int main(){
    vector<int> arr = {1, 3, 2, 4};
    
    // Get result
    vector<int> ans = less_val(arr);

    // Print result
    cout << "The next smaller elements are: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}