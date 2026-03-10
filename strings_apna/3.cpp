#include<bits/stdc++.h>
using namespace std;
int main(){
    // string is dynamic in nature that npo need to define size
    // resized at runtime
    // str array can't change size at runtime
    string str="apna college";
    str="Hello"; //allowed
    char s[]="apna college";
    //s="hello"; //not allowed

    string str1="P";
    string str2="K";

    cout<<str1+str2<<endl;
    cout<<(str1==str2)<<endl;
    cout<<str1.length()<<endl;

}