#include<bits/stdc++.h>
using namespace std;


// sir
// brute same 4 loops o(n^4)
// better O(n^3)

class Solution1 {
public:
        vector<vector<int>> fourSum(vector<int>& arr,int target) {
            int n=arr.size();
            set<vector<int>>st;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    set<long long>hashset;
                    for(int k=j+1;k<n;k++){
                        long long sum=arr[i]+arr[j];
                        sum+=arr[k];
                        long long fourth =target-(sum);
                        if(hashset.find(fourth)!=hashset.end()){
                            vector<int> temp={arr[i],arr[j],arr[k],(int)fourth};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);


                        }
                        hashset.insert(arr[k]);

                    }
                }
            }
            vector<vector<int>> ans(st.begin(),st.end());
            return ans;
        }
};

// optimal
class Solution2 {
public:
        vector<vector<int>> fourSum(vector<int>& nums,int target) {
            int n=nums.size();
            vector<vector<int>>ans;
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                if(i>0 && nums[i]==nums[i-1]) continue;
                for(int j=i+1;j<n;j++){
                    if( j != i+1 && nums[j]==nums[j-1]) continue;
                    int k=j+1;
                    int l=n-1;
                    while(k<l){
                        long long sum=nums[i];
                        sum+=nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum == target){
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            ans.push_back(temp);
                            k++;l--;
                            while(k<l && nums[k]==nums[k-1]) k++;
                            while(k<l && nums[l]==nums[l+1]) l--;

                        }
                        else if(sum<target) k++;
                        else l--;
                    }
                }
            }
            return ans;
        }
    };

/*
mine
1. brute
2. sum of four - sum of three is required fourth element 
3. i at start and k at last p=i+1 and q=k-1 no arr[i]+arr[j] is there then perforn\m same as we did in three sum optimal approach


*/
int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution2 obj;
    vector<vector<int>> ans = obj.fourSum(arr, target);

    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}