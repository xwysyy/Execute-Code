#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 0) return 0;
        
        // dp[i] will store the length of the longest non-increasing subsequence ending at index i
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] >= a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // The length of the longest non-increasing subsequence
        int max_length = *max_element(dp.begin(), dp.end());
        
        // The minimum number of elements to remove
        return n - max_length;
    }
};


#endif