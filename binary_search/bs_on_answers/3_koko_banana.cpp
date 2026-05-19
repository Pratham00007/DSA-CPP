/*
Koko Eating Bananas


12

Problem Statement: A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

Examples
Input: N = 4, a[] = {7, 15, 6, 3}, h = 8
Output: 5
Explanation:  If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  
Input: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
Output: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. 
*/

// sir 
// brute go from i=1 to max no banana/per to eat when you find the hrs<=given hrs stop and return
// tc = max of arr* n

// better bs
// you know your answer lie in 1 to max(arr) so do bs

#include<bits/stdc++.h>
using namespace std;

int findmax(vector<int>arr){
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

int calcTotalHours(vector<int>arr,int hourly){
    int totalH=0;
    for(int i=0;i<arr.size();i++){
        totalH+= ceil((double)arr[i]/(double)hourly);
    }
    return totalH;
}

int min_rate_banana(vector<int>arr,int h){
    int low=1 , high=findmax(arr);
    while(low<=high){
        int  mid=(low+high)/2;
        int totalH=calcTotalHours(arr,mid);
        if(totalH<=h){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    cout<<min_rate_banana({25, 12, 8, 14, 19},5);
}