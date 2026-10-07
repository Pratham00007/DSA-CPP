
#include <bits/stdc++.h>
using namespace std;
double maxAverageScore(int n, int k, vector<int>& arr) {
    double max_sum = 0;
    double curr_sum = 0;

    int left = 0;
    int right = 0;

    while (right < n) {
        curr_sum += arr[right];
        ++right;

        if (right - left >= k) {
            double sum = static_cast<double>(curr_sum) / k;
            max_sum = max(max_sum, sum);
            curr_sum -= arr[left];
            ++left;
        }
    }

    return max_sum;
}

int main() {
    int n = 6;
    int k = 3;
    vector<int> arr = {4,8,5,10,6,7};

    double result = maxAverageScore(n, k, arr);

    cout << "Maximum average score: " << fixed << setprecision(5) << 
result;

    return 0;
}