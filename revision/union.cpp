#include<bits/stdc++.h>
using namespace std;

vector<int>unions(vector<int>arr1,int n,vector<int>arr2,int m){
map<int,int>freq;
for(int i=0;i<n;i++){
    freq[arr1[i]++];
}
for(int j=0;j<m;j++){
    freq[arr2[j]++];
}
vector<int>ans;
for(auto it: freq){
    ans.push_back(it.first);
}
return ans; 
}


vector<int>unions2(vector<int>arr1,int n,vector<int>arr2,int m){
    vector<int>ans;
    int i=0,j=0;

    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        if(arr2[j]<arr1[i]){
            ans.push_back(arr2[j]);
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while(i<n){
        ans.push_back(arr1[i]);
        i++;

    }

    while(j<m){
        ans.push_back(arr2[j]);
        j++;
        
    }

    return ans;
}

int main(){
    vector<int>arr1={1,3,5,8};
    vector<int>arr2={3,7,9,10,15};
    vector<int>ans=unions2(arr1,4,arr2,5);

    for(auto it:ans){
        cout<<it<<" ";
    }
}