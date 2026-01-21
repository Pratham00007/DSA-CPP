// all right to it are smaller then that no is leader 

#include<bits/stdc++.h>
using namespace std;


// mine
// same sir brute fore tc O(n^2) sc O(n)

vector <int> leader(vector<int> arr,int n){
    vector<int> lead;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=i;j<n;j++){

            if (arr[i]<arr[j]){

                flag=1;

            }
        }
        if(flag==0){
            lead.push_back(arr[i]);
        }
        flag=0;
    }
    return lead;
}


// optimal

vector <int> leader2(vector<int> arr,int n){
    int maxi=INT_MIN;
    vector<int> lead;
    for(int i=n-61;i>=0;i--){
        if (arr[i]>maxi){
            lead.push_back(arr[i]);
            maxi=arr[i];
        }
    }
    return lead;
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
    vector<int> result=leader(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
    
}
