#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
public:
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
