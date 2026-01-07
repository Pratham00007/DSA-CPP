// dutch national flag algo

#include <bits/stdc++.h>
using namespace std;


vector<int> dnfa(vector <int>arr,int n){
    int low=0,mid=0,high=n-1;

    while (mid<=high)
    {
        if (arr[mid==0]){
            swap(arr[low],arr[mid]);
            low++;
            mid++;

        }
        else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    
    return arr;
}

int main(){
    vector<int> arr;
    int n;
    cout<<"Enter no of numbers";
    cin>>n;
    int temp;
        

    for(int i=0;i<n;i++){
        cin>> temp;
        arr.push_back(temp);
    }


    vector <int> result=dnfa(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
}