/*
Find the number that appears once, and the other numbers twice


24

Problem Statement: Given a non-empty array of integers arr, every element appears twice 
except for one. Find that single one.

Examples
Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.


Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. 
So, 4 is the answer.
*/

#include<bits/stdc++.h>
using namespace std;

// mine and sir same optimal
int single_no(vector<int>arr){
    int ans=0;
    for(auto it:arr){
        ans=ans^it;
    }
    return ans;
}

int main(){
    vector<int> arr={1,1,2,3,3};
    cout<<single_no(arr);

}