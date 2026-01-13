// Kedans Algorith -> max_sum_subarray


#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int>arr , int n){
    int maximum=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>maximum){
            maximum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maximum;
}

// also want to priont any of the subarray

int max_sum2(vector<int>arr , int n){
    int maximum=INT_MIN;
    int sum=0;
    int ans_start=-1,ans_end=-1;
    int start;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if (sum==0){
            start=i;
        }
        if(sum>maximum){
            maximum=sum;
            ans_start=0;ans_end=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maximum;
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

    cout<<"Max sum of subarray is:"<<max_sum(arr,n);

}