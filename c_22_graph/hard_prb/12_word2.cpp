#include<bits/stdc++.h>
using namespace std;

vector<vector<string>>findsequence(string beginword,string endword,
vector<string>&wordlist){
    unordered_set<string>st(wordlist.begin(),wordlist.end());
    queue<vector<string>>q;
    q.push({beginword});
    vector<string>usedonlevel;
    usedonlevel.push_back(beginword);
    int level=0;
    vector<vector<string>>ans;
    while(!q.empty()){
        vector<string>vec=q.front();
        q.pop();
        if(vec.size()>level){
            level++;
            for(auto it:usedonlevel){
            st.erase(it);}
        }
    

    string word=vec.back();
    if(word==endword){
        if(ans.size()==0){
    ans.push_back(vec);}
    else if(ans[0].size()==vec.size()){
        ans.push_back(vec);
    }
    }

    for(int i=0;i<word.size();i++){
        char original=word[i];
        for(char c='a';c<='z';c++){
            word[i]=c;
            if(st.count(word)>0){
                vec.push_back(word);
                q.push(vec);
                usedonlevel.push_back(word);
                vec.pop_back();
            }
        }
        word[i]=original;
    }

}
return ans;
}