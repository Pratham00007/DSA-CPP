/*

Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

Examples
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Output: [0]

*/
#include  <bits/stdc++.h>
using namespace std;


// mine
vector<int> insort(vector <int> arr,int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (arr[i]<arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return arr;
}

// sir

// brute force ->  merge sort tc: nlogn, sc: n

// better: tc: O(2n) like counting sort

vector<int> insort2(vector<int> arr, int n){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if (arr[i]==0){
            cnt0++;
        }
        else if (arr[i]==1){
            cnt1++;
        }
        else if (arr[i]==2){
            cnt2++;
        }
        else{continue;}
    }

    for(int j=0;j<cnt0;j++) arr[j]=0;
    for(int j=cnt0;j<cnt0+cnt1;j++) arr[j]=1;
    for(int j=cnt0+cnt1;j<n;j++) arr[j]=2;

    return arr;
}

// optimal tc: O(n) -> dutch national flag algo (DNFA)
int main(){
    int n;
    cout<<"enter no of elements";
    cin>>n;
    vector<int> arr;
    for (int j=0;j<n;j++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"after sort"<<endl;
    vector<int> result=insort2(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }



}