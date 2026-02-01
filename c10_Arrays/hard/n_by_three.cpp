#include<bits/stdc++.h>
using namespace std;

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
    vector<int>arr1={1, 2, 1, 1, 3, 2};
    cout<<"After Intersection"<<endl;
    vector<int> result=answ(arr1);
    for(auto it:result){
        cout<<it<<endl;
    }

}