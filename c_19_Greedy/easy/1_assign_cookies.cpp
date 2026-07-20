/*
Assign Cookies


8

Problem Statement: Consider a scenario where a teacher wants to distribute cookies to students,
 with each student receiving at most one cookie. Given two arrays, student and cookie, 
 the ith value in the student array describes the minimum size of cookie that the ith 
 student can be assigned. The jth value in the cookie array represents the size of the 
 jth cookie. If cookie[j] >= student[i], the jth cookie can be assigned to the ith student.
  Maximize the number of students assigned with cookies and output the maximum number.

Examples
Input : Student = [1, 2, 3] , Cookie = [1, 1]
Output :1
Explanation : Only the first cookie (1) satisfies the first student (1), therefore only 1
 student is content.
Input : Student = [1, 2] , Cookie = [1, 2, 3]
Output : 2
Explanation : Cookie 1 satisfies student 1 and cookie 2 satisfies student 2. Therefore, 
2 students are content.
*/

#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(), m=s.size(), l=0,r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(l<m && r<n){
          if(g[r]<=s[l]){
            r=r+1;
          }
          l=l+1;
        }
        return r;

    }

int main(){

}