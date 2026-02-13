/*
Merge Overlapping Sub-intervals



23

Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

Examples
Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]
Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.
Input : [[1,4],[4,5]]
Output :  [[1,5]]
Explanation :  Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].
*/

#include<bits/stdc++.h>
using namespace std;

// sir

vector<vector<int>>ans(vector<vector<int>> arr){
    int n=arr.size();
    vector<vector<int>>answ;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int st=arr[i][0];
        int end=arr[i][1];

        if(!answ.empty() && end<=answ.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0] <=end){
                end=max(end,arr[j][1]);
            }else{break;}
        }
        answ.push_back({st,end});
    }
    return answ;


}


// mine 

// brute
vector<vector<int>>ans(vector<vector<int>> arr){
    int n=arr.size();
    set<int>nno;
    for (int i = 0; i < n; i++)
    {
        for(int j=arr[i][0];j<=arr[i][1];j++){
            nno.insert(j);
        }
    }
vector<vector<int>>answer;
for(int i=0;i<nno.size()-1;i++){
    vector<int>temp;
    // difficult to add according to index ins eet
    if(*next(nno.begin(),i)+1!=*next(nno.begin(),i+1)){

    }
}

    cout<<*next(nno.begin(),0);
    
    
}

// better but some edge case making some error
vector<vector<int>>ans2(vector<vector<int>> arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
        vector<vector<int>>answ;
    for(int i=0;i<n;i++){
        vector<int>temp=arr[i];
        int s=temp[0];
        int j=temp[1];
        for(int k=1;i+k<n;k++){
            if(arr[i+k][0]<=j){
            j=arr[i+k][1];
            i+=k;
            }else{break;}

        }
        answ.push_back({s,j});
        
    }
    return answ;
}


int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = ans2(intervals);

    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}
