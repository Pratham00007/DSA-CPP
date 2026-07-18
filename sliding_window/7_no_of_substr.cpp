/*
Number of substring containing all three characters

Problem Statement: Given a string s , consisting only of characters 'a' , 'b' , 'c'.
Find the number of substrings that contain at least one occurrence of all these 
characters 'a' , 'b' , 'c'.

Examples
Input : s = "abcba"
Output :  5
Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' 
are "abc" , "abcb" , "abcba" , "bcba" , "cba".


Input : s = "ccabcc"
Output : 8
Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' 
are "ccab" , "ccabc" , "ccabcc" , "cab" , "cabc" , "cabcc" , "abc" , "abcc".

*/

#include<bits/stdc++.h>
using namespace std;
int no_substr(string s){
    int lastsum[3]={-1,-1,-1};
    int cnt=0;
    for(int i=0;i<s.size();i++){
        lastsum[s[i]-'a']=i;
        if(lastsum[0]!=-1 && lastsum[1]!=-1 && lastsum[2]!=-1 ) {
            cnt=cnt+(1+min(lastsum[0],lastsum[1],lastsum[2]));

        }
        return cnt;
    }
}
int main(){

}