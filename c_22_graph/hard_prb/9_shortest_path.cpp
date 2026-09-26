#include<bits/stdc++.h>
using namespace std;

void toposort(int node, vector<pair<int,int>>adj[],
int vis[],stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        int v=it.first;
        if(!vis[v]){
            toposort(v,adj,vis,st);
        }
    }
    st.push(node);
}

vector<int>shortestpath(int n,int m, vector<int>edges[]){
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }

    int vis[n]={0};
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,adj,vis,st);
        }
    }

    vector<int>dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();

        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;

            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
    return dist;

}