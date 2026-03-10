#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="aba";
    string temp=s;
    reverse(s.begin(),s.end());
    if (s==temp){
        cout<<"yes";
    }else{cout<<"no";}
}