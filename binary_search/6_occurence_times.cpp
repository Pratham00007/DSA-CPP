/*
Count Occurrences in Sorted Array



Problem Statement: You are given a sorted array 
containing N integers and a number X, you have to find the occurrences of X in the given array.

Examples
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
Explanation:
 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input:
 N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output
: 5
Explanation:
 2 is occurring 5 times in the given array so it is our answer.

*/


#include <bits/stdc++.h>
using namespace std;

// mine optimal-> ub-lb
int occ(vector<int>arr,int target){
    int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
    int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    return ub-lb;
}

// sir SAME AS YOURS

int main(){
    vector<int>arr={1, 1, 2, 2, 2, 2, 2, 3};
    cout<<occ(arr,2);
}