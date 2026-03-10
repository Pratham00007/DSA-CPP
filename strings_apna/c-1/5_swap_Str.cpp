#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// when array str is given 
    void reverseString(vector<char>& s) {
        int st=0;int en=s.size()-1;

        while(st<en){
            swap(s[st],s[en]);
            st++;en--;
        }
    }
// if string is given use reverse funstion
// reverse(str.begin(),str.end())
// str.begin is iterator 

};