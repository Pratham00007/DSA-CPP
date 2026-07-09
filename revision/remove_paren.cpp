#include<bits/stdc++.h>
using namespace std;

string rem(string in){
    string ans="";
    int level=0;
    for(char ch:in){
        if(ch == '('){
            if(level>0){
                ans=ans+'(';
            }
            level++;
        }

        if(ch==')'){
            level--;
            if(level>0){
                ans=ans+')';
            }
        }
    }
return ans;
}

int main(){
    string in="()(()())(())";
    string ans=rem(in);
    cout<<ans;
}