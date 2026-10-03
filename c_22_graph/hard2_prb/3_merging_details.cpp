#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int  findPair(int node){
        if(node==parent[node]) return node;
        return parent[node]=findPair(parent[node]);
    }

    void UnionByRank(int u,int v){
        int ulp_u=findPair(u);
        int ulp_v=findPair(v);
        if(ulp_u==ulp_v) return ;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;

        }else if(rank[ulp_v]<rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};


class Solution{

public:
    vector<vector<string>>mergeDet(vector<vector<string>>&details){
        int n=details.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapmailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string  mail=details[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end()){
                    mapmailnode[mail]=i;
                }else{
                    ds.UnionByRank(i,mapmailnode[mail]);
                }
            }
        }

        vector<string>mergemail[n];
        for(auto it:mapmailnode){
            string mail=it.first;
            int node=ds.findPair(it.second);
            mergemail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(mergemail[i].size()==0) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto it:mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};