#include<bits/stdc++.h>
using namespace std;

int subarr1(vector<int> arr,int n,int target){
    int sum=0;
    int i=0;
    int j=1;
    int len=1;
    sum+=arr[i];
    while (sum<target){
        sum+=arr[j];
        j++;
        len++;
    }
    while (sum-arr[i]+arr[j+1]>sum){
        sum=sum-arr[i]+arr[j+1];
        len++;
    }
    cout<<"max length="<<len;
    return 0;
}
int main(){
    int n;
    cout<<"Enter number of elemnts";
    cin>>n;

    vector<int> arr;
    for (int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"enter the target sum";
    int target;
    cin>>target;
    subarr1(arr,n,target);
}