#include<bits/stdc++.h>
using namespace std;



vector<int>dijk(int v , vector<vector<int>>adj[],int s){

set<pair<int,int>>st;
vector<int>dist(v,1e9);
st.insert({0,s});
dist[s]=0;

while(!st.empty()){
    auto it=*(st.begin());
    int node=it.second;
    int dis=it.first;
    st.erase(it);

    for(auto it:adj[node]){
        int adjnode=it[0];
        int edgew=it[1];

        if(dis+edgew<dist[adjnode]){
            if(dist[adjnode]!=1e9) st.erase({dist[adjnode],adjnode});
        }
    }
}
return dist;

}