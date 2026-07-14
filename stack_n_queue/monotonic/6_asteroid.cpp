/*
Asteroid Collision


3

Problem Statement: Given an array of integers asteroids, 
where each integer represents an asteroid in a row, determine 
the state of the asteroids after all collisions. In this array,
 the absolute value represents the size of the asteroid, and 
 the sign represents its direction (positive meaning right and
  negative meaning left). All asteroids move at the same speed.


When two asteroids meet, the smaller one will explode. 
If they are the same size, both will explode. Asteroids moving in the same 
direction will never meet.

Examples
Example 1:
Input:
 asteroids = [2, -2]
Output:
 []
Explanation:
 The asteroid with size 2 and the one with size -2 collide, exploding each other.

Example 2:
Input:
 asteroids = [10, 20, -10]
Output:
 [10, 20]
Explanation:
 The asteroid with size 20 and the one with size -10 collide, 
 resulting in the remaining asteroid with size 20. 
 The asteroids with sizes 10 and 20 never collide.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>asteroid(vector<int>arr){
    int n=arr.size();
    list<int> st;
    for(int i=0;i<n;i++){
        if(arr[i]>0) st.push_back(arr[i]);
        else{
            while(!st.empty() && st.back()>0 && st.back()<abs(arr[i])) st.pop_back();
            if(!st.empty() && st.back() == abs(arr[i])) st.pop_back();
            else if(st.empty() || st.back()<0) 
            st.push_back(arr[i]);
        }
    }
    return vector<int>(st.begin(),st.end());
}