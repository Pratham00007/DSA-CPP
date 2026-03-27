/*
Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Examples
Example 1:
Input:
 N = 5, array[] = {1,3,2,3,1)
Output
: 2 
Explanation:
 The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

Example 2:
Input:
 N = 4, array[] = {3,2,1,4}
Output:
 1
Explaination: 
There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]
*/

#include <bits/stdc++.h>
using namespace std;

// mine simple for each pair check proceding numbers if they are their <=/2 then cnt++ O(n2) 
int reverse_pairs(vector<int>arr ){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]>2*arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

// sir-> merge sort logic

int main()
{
    vector<int> a = {1,3,2,3,1};
    int n = 5;
    int cnt = reverse_pairs(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}