#include<bits/stdc++.h>
using namespace std;
int main(){
    // char array
    // to make it valid char string use \0
    char str[]={'a','b','c','\0'};
    cout<<str<<endl;
    // to print strling length
    cout<<strlen(str)<<endl;


    // string literal-> value assigned it it the value not changes
    // college value will be colleg3e it doent change
    char str2[]="college";
    cout<<str2<<endl;
    cout<<str2[1]<<endl;
}