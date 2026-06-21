// all theory saved 
// check explain file


// solving leetcode

// complement

#include<bits/stdc++.h>
using namespace std;

string dec2bin(int num){
    
    string bin="";
    while(num!=1){
        if(num%2==1){
            bin=bin+'1';
        }else{
            bin=bin+'0';
        }
        num=num/2;
    }
    reverse(bin.begin(),bin.end());
    
    return bin;
}

/*

string dec2bin(int num){
    
    if (num == 0) return "0";

    string bin = "";

    while (num > 0) {
        bin += (num % 2) + '0';
        num /= 2;
    }

    reverse(bin.begin(), bin.end());
    
    return bin;
}
*/

int bin2dec(string str){
    int n=str.length();
        int num=0;
        int p2=1;
        for(int i=n-1;i>=0;i--){
            if (str[i]=='1'){
                num=num+p2;
            }
            p2=p2*2;
        }

        return num;
}
int findComplement(int num) {
        string bin=dec2bin(num);
        string comp="";
        for(int i=0;i<bin.length();i++){
            if(bin[i]=='1') comp=comp+'0';
            else comp=comp+'1';
        }
       
        int dec=bin2dec(comp);
return dec;
    }

    int main(){
        cout<<findComplement(5);
    }