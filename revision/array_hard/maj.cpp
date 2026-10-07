#include<bits/stdc++.h>
using namespace std;


void maj(vector<int>arr){
    unordered_map<int,int>freq;
    for(auto it:arr){
        freq[it]++;
    }

   for(auto it:freq){
    cout<<it.first<<"->"<<it.second<<endl;
   }

   if(freq.find(1)==freq.end()) cout<<"not found";
   else{auto it=freq.find(1);
            cout<<&it;
        }
}

int main(){
    vector<int>arr={1,1,2,2,7,3,5,3};
    maj(arr);

}