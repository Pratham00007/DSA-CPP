#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        int x1,y1,z1;
        cin>>x1>>y1>>z1;
        
        for(int i=-z1;i<z1;i++){
            bool is_break=false;
            for(int j=-z1;j<z1;j++){
                if(pow(i,2)+pow(j,2)==pow(z1,2)) {
                    ans.push_back({x1+i,y1+j});
                    is_break=true;
                    break;
                }
            }
            if(is_break) break;
        }

    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;

}