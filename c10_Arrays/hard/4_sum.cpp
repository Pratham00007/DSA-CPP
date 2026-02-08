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

/*
mine
1. brute
2. sum of four - sum of three is required fourth element 
3. i at start and k at last p=i+1 and q=k-1 no arr[i]+arr[j] is there then perforn\m same as we did in three sum optimal approach


*/
int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution1 obj;
    vector<vector<int>> ans = obj.fourSum(arr, target);

    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}