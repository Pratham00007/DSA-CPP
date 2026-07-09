
#include<bits/stdc++.h>
using namespace std;

string pre(vector<string>in){
    sort(in.begin(),in.end());
    string first=in[0];
    if(first=="") return "";
    string last=in[in.size()-1];
    int min_len=min(first.size(),last.size());
    int ans=-1;
    for(int i=0;i<min_len;i++){
        if(first[i]!=last[i] ) break;
        ans=i;
    }

    if(ans>=0)return first.substr(0,ans+1);
    else return "";
}

int main(){
    cout<<pre({"gfds", "inter", "inter", "inter"});
}