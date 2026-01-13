// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

#include <bits/stdc++.h>
using namespace std;


// brute force
int max_sum2(vector<int>arr , int n){
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
            }
            maximum=max(sum,maximum);
        }
    }
    return maximum;
}

// better -> O(n^2)
int max_sum3(vector<int>arr , int n){
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
        }
        maximum=max(maximum,sum);
    }
}

// optimal
 
// mine
int max_sum(vector<int> arr,int n){
    int max_sum_arr=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for (int k=i;k<=j;k++){
                 sum+=arr[k];
            }
            if (sum>max_sum_arr){
                max_sum_arr=sum;
            }
        }
    }
    return max_sum_arr;
}

int main(){
    cout<<"enter no of elements:";
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<"Max sum of subarray is:"<<max_sum3(arr,n);

}