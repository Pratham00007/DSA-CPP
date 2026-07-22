/*
Job Sequencing Problem


7

Problem Statement: You are given a set of N jobs where each job comes with a
 deadline and profit. The profit can only be earned upon completing the job 
 within its deadline. Find the number of jobs done and the maximum profit that
  can be obtained. Each job takes a single unit of time and only one job can be 
  performed at a time.

Examples
Example 1:
Input:
  
N = 4, Jobs = {(1, 4, 20), (2, 1, 10), (3, 1, 40), (4, 1, 30)}  
Output:
 2 60  
Explanation:
  
- The 3rd job with a deadline of 1 is performed during the first unit of time.  
- The 1st job is performed during the second unit of time as its deadline is 4.  
Profit = 40 + 20 = 60.  
So, the result is 2 jobs with a total profit of 60.

Example 2:
Input:
  
N = 5, Jobs = {(1, 2, 100), (2, 1, 19), (3, 2, 27), (4, 1, 25), (5, 1, 15)}  
Output:
 2 127  
Explanation:
  
The first and third jobs, both having a deadline of 2, give the highest profit.  
Profit = 100 + 27 = 127.  
So, the result is 2 jobs with a total profit of 127.
*/

#include<bits/stdc++.h>
using namespace std;
    
struct job{
  int id;
  int profit;
  int deadline;

};


bool comp(job a, job b){
  return (a.profit>b.profit);
}

pair<int,int>JobShedule(job arr[],int n){

  sort(arr,arr+n,comp);

  int maxi=arr[0].deadline;

  // getting maximum deadline

  for(int i=1;i<n;i++){
    if(arr[i].deadline>maxi) maxi=arr[i].deadline;
  }

  int slot[maxi+1]={-1};

  
  int countJobs = 0, jobProfit = 0;

  for(int i=0;i<n;i++){
    for(int j=arr[i].deadline;j>0;j--){
      if(slot[j]==-1) {
        slot[j]=i;
        countJobs++;
        jobProfit+=arr[i].profit;
        break;
      }
    }
  }
  return make_pair(countJobs,jobProfit);
}


int main(){

}