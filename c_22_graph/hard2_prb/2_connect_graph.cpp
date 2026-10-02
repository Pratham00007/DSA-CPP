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
    int solve(int n,vector<vector<int>>&edge){
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findPair(u)==ds.findPair(v)){
                cntExtras++;
            }else{
                ds.UnionByRank(u,v);
            }
        }
        int cntc=0;
        for (int i = 0; i < n; i++)
        {
            if(ds.parent[i]==i) cntc++;
        }
        int ans=cntc-1;
        if(cntExtras>=ans) return ans;
        return -1;
        
    }
};