
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>se={'a','b','c'};
int n=3;

vector<vector<char>>bit;
int no_set= (1<<n);

for(int i=0;i<no_set;i++){
    vector<char>temp;
    for(int j=0;j<n;j++){
        if(i & (1<<j) ){
            temp.push_back(se[j]);
        }
    }
    bit.push_back(temp);
}

for(int i=0;i<bit.size();i++){
   for(int j=0;j<bit[i].size();j++){
    cout<<bit[i][j];
   }
   cout<<endl;
}

}