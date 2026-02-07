/*
3 Sum : Find triplets that add up to a zero


Problem Statement: Given an array of N integers, your task is to find unique triplets that
 add up to give a sum of zero. In short, you need to return an array of all the unique 
 triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

Pre-requisite: 2 Sum Problem

Examples
Example 1:
Input:
 nums = [-1,0,1,2,-1,-4]
Output:
 [[-1,-1,2],[-1,0,1]]
Explanation:
 Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the
 condition of summing up to zero with i!=j!=k


Example 2:
Input:
 nums=[-1,0,1,0]
Output:
 Output: [[-1,0,1],[-1,1,0]]
Explanation:
 Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0]
  satisfy the condition of summing up to zero with i!=j!=k
*/

#include<bits/stdc++.h>
using namespace std;


// sir brute force

class Solution1 {
public:
        vector<vector<int>> threeSum(vector<int>& arr) {
            int n=arr.size();
            set<vector<int>>st;
            for(int i=0;i<n;i++){
                for(int k=i+1;k<n;k++){
                    for(int j=k+1;j<n;j++){
                        if(arr[i]+arr[k]+arr[j] == 0 ){
                            vector<int> temp={arr[i],arr[j],arr[k]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                
                }
            }
            vector<vector<int>>ans(st.begin(),st.end());
            return ans;
        }
};

// better look for third element  = - (first + second)

class Solution2 {
public:
        vector<vector<int>> threeSum(vector<int>& arr) {
            int n = arr.size();
            set<vector<int>>st;
            for(int i=0;i<n;i++){
                set<int>hashset; // reintialze to emty again when start
                for(int j=i+1;j<n;j++){
                    int third=-(arr[i]+arr[j]);
                    if(hashset.find(third)!=hashset.end()){ // must not be last ie must be in set 
                        vector<int> temp={arr[i],arr[j],third};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(arr[j]);
                }
            }
            vector<vector<int>>ans(st.begin(),st.end());
            return ans;
        }
    };

// optimal


class Solution3 {
public:
        vector<vector<int>> threeSum(vector<int>& arr) {
            int n = arr.size();
            vector<vector<int>>ans;
            sort(arr.begin(),arr.end());
            for(int i=0;i<n;i++){
                if(i>0 && arr[i]==arr[i-1]) continue; //that is skip the rest of code
                int j=i+1, k=n-1;
                while (j<k)
                {
                    int sum=arr[i]+arr[j]+arr[k];
                    if(sum<0){
                        j++;
                    }else if(sum>0){
                        k--;
                    }else{
                        vector<int>temp={arr[i],arr[j],arr[k]};
                        ans.push_back(temp);
                        j++;k--;
                        while(j<k && arr[j]==arr[j-1])j++;
                        while(k>j && arr[k]==arr[k+1])k--;
                    }
                }
                
            }
            return ans;
        }
    };
// mine same to sir

class Solution {
public:
        vector<vector<int>> threeSum(vector<int>& arr) {
            
        int n=arr.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=0;k<n;k++){
                    if(arr[i] != arr[j] && arr[j]!=arr[k] && arr[i]!=arr[k]){
                        if((arr[i]+arr[j]+arr[k])==0){
                            // wanna sort then add but i am unable
                            ans.push_back({arr[i],arr[j],arr[k]});
                        }
                    }
                }
            }
        }
        return ans;


    }
};
int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    Solution3 obj;
    vector<vector<int>> res = obj.threeSum(arr);

    for (auto &triplet : res) {
        for (auto &num : triplet) cout << num << " ";
        cout << endl;
    }
    return 0;
}

