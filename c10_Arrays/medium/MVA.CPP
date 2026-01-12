//  monne's voting algorithm for n/2 terms

// tc: O(n) + O(n)


# include<bits/stdc++.h>
using namespace std;
int mva(vector<int>arr,int n){
    int cnt=0;int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt++;
            el=arr[i];
        }else if(arr[i]==el){
            cnt++;
        }else{
            cnt--;
        }
    }
int cnt1=0;
for(int j=0;j<n;j++){
    if (arr[j]==el) cnt1++;
}

if(cnt1>n/2){
    return el;
}
return -1;
}

int main(){
    int n;
    cout<<"Enter no of Elements: ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"Required Element: "<<endl;
    cout<<mva(arr,n);
}
