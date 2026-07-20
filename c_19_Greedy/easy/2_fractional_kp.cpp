/*
Fractional Knapsack Problem : Greedy Approach


Problem Statement: The weight of N items and their corresponding values are given.
 We have to put these items in a knapsack of weight W such that the total value 
 obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Examples
Example 1:
Input:
 val = [60, 100, 120], wt = [10, 20, 30], capacity = 50  
Output:
 240.000000  
Explanation:
  
- Take item 0 (w = 10, v = 60)  
- Take item 1 (w = 20, v = 100)  
- Take 2⁄3 of item 2 (w = 20, v = 80)  
Total value = 60 + 100 + 80 = 240

Example 2:
Input:
 val = [60, 100], wt = [10, 20], capacity = 50  
Output:
 160.000000  
Explanation:
  
Both items fit entirely since total weight 10 + 20 = 30 ≤ 50.  
Total value = 60 + 100 = 160
*/

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool static comp(Item a, Item b){
    double r1=(double) a.value / (double) a.weight;
    double r2=(double) b.value / (double) b.weight;
    return r1>r2;
    
}


double frackp(int w, Item arr[],int n){
    sort(arr,arr+n,comp);

    int currweight=0;
    double fianlval=0.0;

    for(int i=0;i<n;i++){

        if(currweight+arr[i].weight<=w){
            currweight+=arr[i].weight;
            fianlval=arr[i].value;
        }else{
            int remain=w-currweight;
            fianlval+=(arr[i].value / (double) arr[i].weight)*(double)remain;
            break;
        }
    }
    return fianlval;
}

int main(){

}
