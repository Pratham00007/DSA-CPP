// {'a','a','b','b','b','c'}
// return inplace {'a','2','b','3','c','1'}

/*
mine appraoch
1. hashmap
2. 2 pointer approach

*/

// maam
// O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;

        for(int i=0;i<n;i++){
            char ch=chars[i];
            int count=0;

            while(i<n && chars[i]==ch){
                count++;i++;
            }

            if(count==1){
                chars[idx++]=ch;
            }else{
                chars[idx++]=ch;
                string str=to_string(count);
                for(char dig: str){
                    chars[idx++]=dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
    
};