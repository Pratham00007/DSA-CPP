#include<bits/stdc++.h>
using namespace std;


vector<int>dijk(int v , vector<vector<int>>adj[],int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>dist(v);
    for(int i=0;i<v;i++) dist[i]=1e9;

dist[s]={0};
pq.push({0,s});

while(!pq.empty()){
    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it:adj[node]){
        int edgewt=it[1];
        int adjnode=it[0];

        if(dis+edgewt<dist[adjnode]){
            dist[adjnode]=dis+edgewt;
            pq.push({dist[adjnode],adjnode});
        }
    }
}
return dist;
}