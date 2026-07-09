
#include<bits/stdc++.h>
using namespace std;


string odd(string in){
    int n=in.size();
    int lr=-1;
    int i;
    for(int i=n-1;i>=0;i--){
        if((in[i]-'0') %2 != 0) {
            lr=i;
            break;
        }
    }

    i=0;
    while(i<lr && in[i]=='0') i++;

    return in.substr(i,lr);
}


int main(){
    string in="0213650";
    string ans=odd(in);
    cout<<ans;
}