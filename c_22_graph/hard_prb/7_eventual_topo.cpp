#include<bits/stdc++.h>
using namespace std;

vector<int>eventual_Safe(int v,vector<int>adj[]){
    vector<int>adjRev[v];
    int indegree[v]={0};
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int>q;
    vector<int>safenodes;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        safenodes.push_back(node);
        for(auto it:adjRev[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }

    sort(safenodes.begin(),safenodes.end());
    return safenodes;

}