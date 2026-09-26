#include<bits/stdc++.h>
using namespace std;

bool dfscheck(int node,vector<int>adj[],
    int vis[],int pathvis[],int check[]){

        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;

        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfscheck(it,adj,vis,pathvis,check)==true){
                    check[node]=0;
                    return true;
                }
            }

            else if(pathvis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    
}

vector<int> eventualsafenodes(int v,vector<int>adj[]){
    int vis[v]={0};
    int pathvis[v]={0};
    int check[v]={0};
    vector<int>safenode;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfscheck(i,adj,vis,pathvis,check);

        }
    }
    for(int i=0;i<v;i++){
        if(check[i]==1) safenode.push_back(i);
    }
    return safenode;
}