/*
Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
*/

#include<bits/stdc++.h>
using namespace std;

// Brute force ->mine

int subarray3(vector<int> arr,int n,int target){
    int len=0;
    for (int i=0;i<n;i++){
        vector<int> temp;
        
        for (int j=i;j<n;j++){
            temp.push_back(arr[j]);
            if (accumulate(temp.begin(),temp.end(),0)==target && temp.size()>len){
                len=temp.size();
            }
        }
    }
    return len;
}

// bruteforce sir
int subarray4(vector<int> arr,int n,int target){
    int len=0;
    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=i;j<n;j++){
           sum+=arr[j];
           if (sum==target){
            len=max(len,j-i+1);
           }
        }
    }
    return len;
}

// better -> samjh nhi aaya

// optimal
/*
two pointer approach 
let se add karo 
sum me add karte jao
if sum>target 
left index ka element hatao righ ka daaloo
and still if sum=target tab bhi len me store karwa do lenght of subarray 
but shift to right subtracting left if that lenght > prevoious store that
if sum> target subtract left again add right 
*/

int subarray2(vector<int> arr,int n,int target){
    int sum = arr[0];
    int maxlen=0;
    int left=0;
    int right =0;
    while (right<n){
        while(left<=right && sum>target){
            sum-= arr[left];
            left++;
        }
        if(sum==target){
            maxlen=max(maxlen,right-left+1);

        }
        right++;
        if(right<n) sum += arr[right];
        

    }
    return maxlen;
}

int subarray5(vector<int> arr,int n,int target){
    int i=0;
    int j=0;
    int len=0;
    int sum=0;
    while(j<n){
        sum+=arr[j];
        if (sum>target){
            sum=sum-arr[i];
            i++;
            len=max(len,j-i+1);
        }
        len=j-i+1;
        j++;
    }
    return len;
}


 int main(){
    cout<<"ENTER NO OF ELEMENTS: ";
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int target;
    cout<<"Enter the target";
    cin>>target;
    cout<<"max size of sub array "<<subarray5(arr,n,target);
 }