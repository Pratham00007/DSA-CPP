#include<bits./stdc++.h>
using namespace std;

// sir

// brute force
vector<int> alt2(vector<int>arr,int n){
    vector<int> pos_arr;
    vector<int> neg_arr;

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos_arr.push_back(arr[i]);
        }else{
            neg_arr.push_back(arr[i]);
        }
    }
    arr.clear();
    for (int j=0;j<n/2;j++){
        arr.push_back(pos_arr[j]);
        arr.push_back(neg_arr[j]);
        
    }

    return arr;
}


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

    cout<<"result array is:"<<endl;
    vector<int> result=alt2(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
    
}
