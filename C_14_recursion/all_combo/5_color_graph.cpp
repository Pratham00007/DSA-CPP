/*
M - Coloring Problem

Problem Statement: Given an undirected graph and a number m,
 determine if the graph can be colored with at most m colors such 
 that no two adjacent vertices of the graph are colored with the same color.

Examples
Example 1:
Input:
  
N = 4  
M = 3  
E = 5  
Edges[] = {  
  (0, 1),  
  (1, 2),  
  (2, 3),  
  (3, 0),  
  (0, 2)  
}  
Output:
 1  
Explanation:
  
It is possible to color the given graph using 3 colors, so the answer is 1 (possible).

Example 2:
Input:
  
N = 3  
M = 2  
E = 3  
Edges[] = {  
  (0, 1),  
  (1, 2),  
  (0, 2)  
}  
Output:
 0  
Explanation:
  
It is not possible to color the graph using 2 colors as it forms a triangle,
 which requires at least 3 colors. Hence, the answer is 0 (not possible).

*/


#include<bits/stdc++.h>
using namespace std;

bool issafe(int node,int color[],bool graph[101][101],int n, int col  ){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}

bool solve(int node,int color[],int m,int N,bool graph[101][101]){
    if(node==N) return true;

    for(int i=1;i<=m;i++){
        if(issafe(node,color,graph,N,i)){
            color[node]=i;

            if (solve(node+1,color,m,N,graph))  return true;
            color[node]=0;

        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = { 0 };
    // Start solving from node 0
    if (solve(0, color, m, N, graph)) return true;
    return false;
}