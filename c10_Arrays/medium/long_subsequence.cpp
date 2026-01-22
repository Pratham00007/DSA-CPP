/*

Longest Consecutive Sequence in an Array

Problem Statement: Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Examples
Example 1:
Input:
 nums = [100, 4, 200, 1, 3, 2]  
Output:
 4  
Explanation:
 The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:
Input:
 nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output:
 9  
Explanation:
 The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.

 */

 // all right to it are smaller then that no is leader 

#include<bits/stdc++.h>
using namespace std;

// sir

// brute force
bool ls(vector<int>arr,int ele){
    for(int i=0;i<arr.size();i++){
        if (arr[i]==ele){return true;}
        
    }return false;
}
int subsequent2(vector<int> arr,int n){
    int longest=1;
    for(int i=0;i<n;i++){
        int cnt=1;
        int ele=arr[i];
        while(ls(arr,ele+1)==true){
            ele++;
            cnt++;
        }
        longest=max(longest,cnt);
    }
    return longest;

}
// better
int subsequent3(vector<int>arr,int n){
    sort(arr.begin(),arr.end());
    int last_smallest=INT_MIN;
    int longest=1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]-1==last_smallest){
            cnt++;
            last_smallest=arr[i];
        }else if(arr[i]-1 != last_smallest){
            cnt=1;
            last_smallest=arr[i];
        }
        longest=max(longest,cnt);
    }
    return longest;
}


// otimalal -> not u

int subsequent4(vector<int> arr,int n){
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;

            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}

// mine

int subsequent(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    int maxi=0;
    arr.push_back(INT_MAX);
    n=n+1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]+1){
            maxi=max(maxi,i-maxi);
        }
    }
    return maxi;
}


int main(){
    cout<<"enter no of elements:"; 
    int n;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<subsequent4(arr,n);
    
    
}
