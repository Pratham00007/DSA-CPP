#include<bits./stdc++.h>
using namespace std;

// mine two pointer approach -> under progress tc: O(n) sc:O(n)
vector<int> alt(vector<int>arr,int n){
    int pos_postion=0,neg_postion=0;
    vector<int> arr2;
    while(pos_postion<=n && neg_postion<=n){
        if (arr[pos_postion]>0){
            arr2.push_back(arr[pos_postion]);
            
        }
    }
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

    cout<<"Max sum of subarray is:";

}
