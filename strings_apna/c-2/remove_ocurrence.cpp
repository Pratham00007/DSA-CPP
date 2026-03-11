#include <bits/stdc++.h>
using namespace std;

string removed_occurence(string str,string part){
    while(str.length()>0 && str.find(part)<str.length()){
        str.erase(str.find(part),part.length());
    }
    return str;
}
int main(){
    
}