/*
Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

Examples

Example 1:
Input Format: N = 3, nums[] = {3,2,3}
Result: 3
Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

Example 2:
Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}

Result: 2

Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.



*/
#include <bits/stdc++.h>
using namespace std;

// brute force
int max_n2(vector<int> arr,int n){
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<n;j++){
            if (arr[j]==arr[i]) cnt++;

        }
        if (cnt>=n/2) return arr[i]; 
    }
    return 0;
}


// better: hasing - counting sort technique
int max_n3(vector<int> arr, int n){

    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for (auto it:mpp){
        if (it.second>=n/2){
            return it.first;
        }
    }

    return -1;

    // tc: O(N)+O(nlogtgn)
    // sc: O(n)

    
}

// MOONE VOTING ALGORITHM -> OPTRIMALO


// mine
int max_n(vector<int> arr, int n){
    set<int> a;
    int times=0;
    for(int i=0;i<n;i++){
        a.insert(arr[i]);
    }
    for(auto it:a){    
        for(int j=0;j<n;j++){
            if (it==arr[j]){
                times++;
            }
        }
        if (times>=n/2){
            return it;
        }
    }
}

// or use counting sort technique 
int main(){
    int n;
    cout<<"Enter no of Elements: ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"Required Element: "<<endl;
    cout<<max_n3(arr,n);
}