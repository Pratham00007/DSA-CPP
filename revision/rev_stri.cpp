
#include<bits/stdc++.h>
using namespace std;


string rev(string in){
    string ans="";
    vector<string>words;
    int n=in.size();
     string word="";
    for(int i=0;i<n;i++){
       
        if(in[i]!=' '){
            word=word+in[i];
        }
        else if(!word.empty()){
            words.push_back(word);
            word="";
        }       

    }

 if(!word.empty()){
            words.push_back(word);
            word="";
        }

reverse(words.begin(),words.end());
int j=words.size();
for(int i=0;i<j;i++){
    ans=ans+words[i];
    if(i!=j-1){
        ans=ans+' ';
    }
}

return ans;

}


int main(){
    string in="welcome to the jungle";
    string ans=rev(in);
    cout<<ans;
}