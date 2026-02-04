#include<bits/stdc++.h>
using namespace std;



// sir brute force hashing
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

// sir optimal moones voting algo approach

vector<int> answ(vector<int> arr){
    int ele1=INT_MIN,ele2=INT_MIN;
    int cnt1=0,cnt2=0;
    for(int i=0;i<arr.size();i++){
        if(cnt1==0 && ele2!=arr[i]){
            cnt1=1;
            ele1=arr[i];
        }
        else if(cnt2==0 && ele1!=arr[i]){
            cnt2=1;
            ele2=arr[i];
        }
        else if(arr[i]==ele1){cnt1++;}
        else if(arr[i]==ele2){cnt2++;}
        else{
            cnt1--;cnt2--;
        }
        
    }
    // validating
    cnt1=0;cnt2=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==ele1){cnt1++;}
        else if(arr[i]==ele2){cnt2++;}

    }
    int mini=n/3+1;
    vector<int>res;
    if (cnt1>=mini){res.push_back(ele1);}
    if(cnt2>=mini){
        res.push_back(ele2);
    }
    return res;
}


// mine
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