/*
Next Greater Element Using Stack


7

Problem Statement: Given an integer array A, return the next greater element for every
 element in A. The next greater element for an element x is the first element 
 greater than x that we come across while traversing the array in a clockwise manner. 
 If it doesn't exist, return -1 for this element.

Examples
Input: arr = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: In the array, the next larger element to 1 is 3, 3 is 4, 2 is 4 
and for 4 is -1, since it does not exist.
Input : arr = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation : In the array, the next larger element to 6 is 8, for 8 there is
 no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 
 3 there is no larger element on the right and hence -1.
*/

#include<bits/stdc++.h>
using namespace std;


vector<int>ans(vector<int>arr){
    int n=arr.size();
    vector<int>gre;
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        int num=arr[i];
        
        while(!st.empty() && st.top()<num){
            st.pop();
        }
        if(st.empty()){           
            gre.push_back(-1);
        }else{
            gre.push_back(st.top());
        }
        st.push(arr[i]);

    }
    reverse(gre.begin(),gre.end());
    return gre;
}

// leetcode solving
int ans(int start,vector<int>arr){
    int n=arr.size();
    vector<int>gre;
    stack<int>st;

    for(int i=n-1;i>=start;i--){
        int num=arr[i];
        
        while(!st.empty() && st.top()<num){
            st.pop();
        }
        if(st.empty()){           
            gre.push_back(-1);
        }else{
            gre.push_back(st.top());
        }
        st.push(arr[i]);

    }
    reverse(gre.begin(),gre.end());
    return gre[0];
}

int ind(int n,vector<int>nums2){
    for(int i=0;i<nums2.size();i++){
        if(nums2[i]==n) return i;
        
    }
    return -1;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>answers;
        for(int i=0;i<nums1.size();i++){
            int index=ind(nums1[i],nums2);
            int  greater_no=ans(index,nums2);
            answers.push_back(greater_no);
        }
        return answers;
}

int main(){
    vector<int>que={1, 3, 2, 4};
    vector<int>sol=ans(que);

// leetcode
vector<int>nums1={4,1,2};
vector<int>nums2={1,3,4,2};
vector<int>answer=nextGreaterElement(nums1,nums2);



    for(int i=0;i<answer.size();i++){
        cout<<answer[i];
    }
}