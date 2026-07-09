#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     // Check if 'goal' is a rotation of 's'
//     bool rotateString(string& s, string& goal) {
//         // Strings must be same length to be rotations of each other
//         if (s.length() != goal.length()) {
//             return false;
//         }
//         // Try all possible rotations of 's'
//         for (int i = 0; i < s.length(); i++) {
//             string rotated = s.substr(i) + s.substr(0, i);  
//             cout<<rotated<<endl;
//             if (rotated == goal) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// int main() {
//     Solution sol;
//     string s = "rotation";
//     string goal = "tionrota";
    
//     // Output the result
//     if (sol.rotateString(s, goal)) {
//         cout << "true" << endl;  
//     } else {
//         cout << "false" << endl;
//     }

//     return 0;
// }

int main(){
string s="012";
cout<<s.substr(0);
}