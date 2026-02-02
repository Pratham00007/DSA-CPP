#include<bits/stdc++.h>
using namespace std;



// sir brute force
vector<int> answ2(vector<int> arr){
    vector<int>ls;
    int n=arr.size();
    map<int,int>mpp;
    for (int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==n/3+1){
            ls.push_back(arr[i]);
        }
    }
    return ls;
}

vector<int> answ(vector<int> arr){
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if (arr[i]==arr[j]){
                cnt++;
            }      
            
        }if (cnt>n/3){
            if(find(ans.begin(), ans.end(), arr[i]) == ans.end()){
                ans.push_back(arr[i]);
            }
                
            }
    }
    return ans;
}

int main(){
    vector<int>arr1={1, 2, 1, 1, 3, 2,2};
    cout<<"After Intersection"<<endl;
    vector<int> result=answ2(arr1);
    for(auto it:result){
        cout<<it<<endl;
    }

}