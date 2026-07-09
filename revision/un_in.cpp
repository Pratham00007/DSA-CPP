
#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>arr1={1,2,3,4,5,6};
    vector<int>arr2={2,4,8,9};

    map<int,int>freq;
    for(int i=0;i<arr1.size();i++){
        freq[arr1[i]]++;
    }

    for(int i=0;i<arr2.size();i++){
        freq[arr2[i]]++;
    }

    vector<int>un;
    vector<int>ine;
    
    for(auto& it:freq){
        if(it.second>1){
            ine.push_back(it.first);
        }
        un.push_back(it.first);
    }

    for(int i=0;i<un.size();i++){
        cout<<un[i];
    }
    cout<<endl;
    for(int i=0;i<ine.size();i++){
        cout<<ine[i];
    }
}
