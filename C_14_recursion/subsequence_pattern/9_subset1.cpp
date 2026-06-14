/*
Subset Sum : Sum of all Subsets


7

Problem Statement: Given an array print all the sum of the subset generated from it, 
in the increasing order.

Examples

Input: N = 3, arr[] = {5,2,1}
Output: 0,1,2,3,5,6,7,8
Explanation: We have to find all the subset’s sum and print them.in this case the 
generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums 
we get will be  0,1,2,3,5,6,7,8

Input: N=3,arr[]= {3,1,2}
Output: 0,1,2,3,3,4,5,6
Explanation: We have to find all the subset’s sum and print them.in this case the 
generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums 
we get will be  0,1,2,3,3,4,5,6
*/


#include<bits/stdc++.h>
using namespace std;

void func(int ind, int sum,vector<int>&arr,int N,vector<int>&sumSubset){
    if(ind==N){
        sumSubset.push_back(sum);
        return ;
    }

    func(ind+1,sum+arr[ind],arr,N,sumSubset);

    func(ind+1,sum,arr,N,sumSubset);
}

vector<int>subsetSums(vector<int>arr,int N){
    vector<int>sumSubset;
    func(0,0,arr,N,sumSubset);
    sort(sumSubset.begin(),sumSubset.end());
    return sumSubset;
}