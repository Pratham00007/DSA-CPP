// valid palindrome-> canbe alpha numeric, 
// if non alphanumeric skip that chracter 

#include <bits/stdc++.h>
using namespace std;

bool isaplanum(char s){
    if((tolower(s)>='a' && tolower(s)<='z') || (s>='0' && s<='9') ){
        return true;
    }
    return false;
}

bool isvalidPalin(string str){
    int st=0,en=str.length()-1;
    while(st<en){
        if(!isaplanum(str[st])){
            st++;continue;
        }
        if(!isaplanum(str[en])){
            en--;continue;
        }

        if(tolower(str[st]) != tolower(str[en])){
            return false;
        }
        st++;en--;
    }
    return true;

}
int main(){}