#include<bits/stdc++.h>
using namespace std;
int main(){
    // str input simalarly cin make space breaks input
    // use getline
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    cout<<"Entered string is "<<str<<endl;

    // iternation
    for(int i=0;i<str.length();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
}