#include<bits/stdc++.h>
using namespace std;

void sol(vector<int>arr,int no){
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<no;i++){
        if(arr[i]==1){
            st.push(i+1);
        }else if(arr[i]==2){
            if(!st.empty()) {
                st.pop();
                ans.push_back(i+1);
            
            }
           
        }else if(arr[i]==3){
            continue;
        }
    }
    while(st.size()!=0){
        ans.push_back(st.top());
        st.pop();
    }

    int n=ans.size();
    if(n==0){
        cout<<0<<endl;

    }else{
        sort(ans.begin(),ans.end());
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
            
        }
        
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>ma_ar;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        vector<int>arr;
        
            string temp;
            cin>>temp;
            for(auto it:temp){
                arr.push_back(it-'0');
            }
            
        
        ma_ar.push_back(arr);
       
    }
    for(int i=0;i<n;i++){
        sol(ma_ar[i],ma_ar[i].size());
    }
    return 0;
}