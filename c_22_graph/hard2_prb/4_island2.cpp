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

private:

    bool isvalid(int adjr,int adjc,int n, int m){
        return adjr>=0 && adjr<n && adjc>=0 && adjc<m;
    }

public:

    vector<int>numofisland(int n,int m,vector<vector<int>>&operators){
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int>ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;

            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};

            for(int ind=0;ind<4;ind++){
                int adjr=row+dr[ind];
                int adjc=col+dc[ind];
                if(isvalid(adjr,adjc,n,m)){
                    if(vis[adjr][adjc]==1){
                        int nodeNo=row*m+col;
                        int adjNodeNo=adjr*m+adjc;
                        if(ds.findPair(nodeNo) != ds.findPair(adjNodeNo)){
                            cnt--;
                            ds.UnionByRank(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }

};