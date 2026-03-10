#include<bits/stdc++.h>
using namespace std;
int main(){
//     char str[100]; //can't defined un sized empty
//     cout<<"Enter char array: ";
//     cin>>str;
// // cin take input till space after space t\it ignore all the inputs so we use getline
//     cout<<"Output: "<<str<<endl;

    // char str[100];
    // cout<<"Enter the char array ";
    // cin.getline(str,100); //by default deli=\n
    // cout<<"Output: "<<str<<endl;

    // char str2[100];
    // cout<<"Enter the char array ";
    // cin.getline(str2,100,'$'); //by default deli=\n
    // cout<<"Output: "<<str2<<endl;

    // for(char ch:str){
    //     cout<<ch<<" ";
    // }
    // cout<<endl;

// finding length of string
char str[]="Apna College";
int len=0;

for(int i=0; str[i]!= '\0';i++){
    len++;
}

cout<<"length of string is "<<len<<endl;

}