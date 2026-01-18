#include<bits./stdc++.h>
using namespace std;

// sir

// brute force sc=O(2N) sc=O(N)
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
    for (int j=0;j<n/2;j++){
        arr[2*j]=pos_arr[j];
        arr[2*j+1]=neg_arr[j];
        
    }

    return arr;
}

// optimal:same as mine. sc=O(N) tc=O(n)
vector<int> alt3(vector<int>arr,int n){
    int pos=0,neg=1;
    vector<int> new_Arr(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            new_Arr[pos]=arr[i];
            pos+=2;
        }else{
            new_Arr[neg]=arr[i];
            neg+=2;
        }

    }
    return new_Arr;
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

// type-2 if any left then add them in last use brute force one bcs optimal cant
vector<int> alt4(vector<int>arr,int n){
    vector<int> pos_arr;
    vector<int> neg_arr;

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos_arr.push_back(arr[i]);
        }else{
            neg_arr.push_back(arr[i]);
        }
    }
    if(pos_arr.size()>neg_arr.size()){
        for(int i=0;i<neg_arr.size();i++){
            arr[2*i]=pos_arr[i];
            arr[2*i+1]=neg_arr[i];
        }
        int index=neg_arr.size()*2;
        for(int i=pos_arr.size();i<neg_arr.size();i++){
            arr[index]=pos_arr[i];
            index++;
        }
    }else{
        for(int i=0;i<pos_arr.size();i++){
            arr[2*i]=pos_arr[i];
            arr[2*i+1]=neg_arr[i];
        }
        int index=pos_arr.size()*2;
        for(int i=pos_arr.size();i<neg_arr.size();i++){
            arr[index]=neg_arr[i];
            index++;
        }

    }

    return arr;
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
    vector<int> result=alt4(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
    
}
