/*
K-th Element of two sorted arrays

Problem Statement: Given two sorted arrays a and b of size m and n respectively. 
Find the kth element of the final sorted array.

Examples
Example 1:
Input:
 a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5  
Output:
 6  
Explanation:
 The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2:
Input:
 a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7  
Output:
 256  
Explanation:
 The final sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. 
 The 7th element of this array is 256.
*/

// mine 
// without sc like earlier inteasd of merging take cnt variable

#include<bits/stdc++.h>
using namespace std;

int kele(vector<int>arr1, vector<int>arr2, int k){
    int i=0 , j=0;
    int cnt=0;
    int n1=arr1.size();
    int n2=arr2.size();
    int ele=INT_MIN;
    while(i<n1 && j <n2){
        if(arr1[i]<arr2[j]){            
            if (cnt==k){
                return arr1[i];
            }
            i++;
            cnt=i+j;
            
        }else{
            if(cnt==k){
                return arr2[j];
            }
            j++;
            cnt=i+j;
        }
        
    }

    while (i<n1){
        if (cnt==k){
                return arr1[i];
            }
            i++;
            cnt=i+j;

    }
    while(j<n2){
        if(cnt==k){
                return arr2[j];
            }
            j++;
            cnt=i+j;
    }
    return -1;   

}

// sir bs like earlier 12 median just k element is needed on left and rest on right of symmetry
int kele2(vector<int>a,vector<int>b,int n1,int n2, int k){
    if(n1>n2) return kele2(b,a,n2,n1,k); // just swapperd 
    int low=max(k-n2,0),high=min(k,n1);
    int left =k;
    int n=n1+n2;
    while(low<=high){
        int mid1=(low+high) >> 1;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;

        if(mid1<n1) r1=a[mid1];
        if(mid2<n2) r2=b[mid2];

        if(mid1-1 >=0) l1=a[mid1-1];
        if(mid2-1 >=0) l2=b[mid2-1];
        if(l1<=r2 && l2 <=r1){
            return max(l1,l2);
        }
        else if(l1>l2) high=mid1-1;
        else low=mid1+1;
        

    }
    return 0;
}


int main() {
    vector<int> a = {100, 112, 256, 349, 770};
    vector<int> b = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;

    cout<< kele2(a,b,5,7,k);
}