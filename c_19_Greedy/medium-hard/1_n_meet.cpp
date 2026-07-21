/*
N meetings in one room


8

Problem Statement: There is one meeting room in a firm. You are given two arrays, 
start and end each of size N. For an index ‘i’, start[i] denotes the starting time 
of the ith meeting while end[i] will denote the ending time of the ith meeting. 
Find the maximum number of meetings that can be accommodated if only one meeting 
can happen in the room at a particular time. Print the order in which these meetings 
will be performed.

Examples
Input: N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
Output: [1, 2, 4, 5]
Explanation: These meeting can be conducted in the room.


Input: N = 2, start[] = {1,5}, end[] = {7,8}
Output: [1]
Explanation: Any one out of the two meeting can take place.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>maxMeet(vector<int>&start,vector<int>&end){
    vector<tuple<int,int,int>>meetings;
    for(int i=0;i<start.size();i++){
        meetings.push_back({end[i],start[i],i+1});
    }

    sort(meetings.begin(),meetings.end());

    vector<int>result;
    int lastend=-1;

    for(auto&m:meetings){
        int e=get<0>(m);
        int s=get<1>(m);
        int idx=get<2>(m);

        if(s>lastend){
            result.push_back(idx);
            lastend=e;

        }


    }
    return result;

}


int main(){

}