#include<bits/stdc++.h>
using namespace std;

bool ispossibel(int v, vector<pair<int,int>>&prerequisites){
    vector<int>adj[v];
    for(auto it:prerequisites){
        adj[it.first].push_back(it.second);
    }

    int indegre[v]={0};
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indegre[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegre[i]==0){
            q.push(i);
        }
    }

    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);

        for(auto it:adj[node]){
            indegre[it]--;
            if(indegre[it]==0) q.push(it);
        }
    }
    if(topo.size()==v) return true;
    return false;
}